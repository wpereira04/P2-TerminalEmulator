////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: mypipe.cpp
// Description: Contains the implementations for the mypipe
// functions
//				
// Date:        04/20/2025
//

#include "mypipe.h"

mypipe::mypipe() {
	if (pipe(fd.data()) == -1) {
		throw std::runtime_error("Failed to create pipe");
	}
}

mypipe::~mypipe() {
	if (fd[0] != -1) close(fd[0]);
	if (fd[1] != -1) close(fd[1]);
}

void mypipe::redirect() {
	if (dup2(fd[1], STDOUT_FILENO) == -1) {
		throw std::runtime_error("Redirecting Failed");
	}
	close(fd[1]);
	fd[1] = -1;
}

std::string mypipe::read() {
    const size_t buffSize = 4096;
    std::vector<char> buffer(buffSize);
    std::string output;

    ssize_t bytesRead;
    while ((bytesRead = ::read(fd[0], buffer.data(), buffSize)) > 0) {
        output.append(buffer.data(), bytesRead);
    }

    if (bytesRead == -1) {
        throw std::runtime_error("Failed to Read");
    }

    close(fd[0]);
    fd[0] = -1;

    return output;
}