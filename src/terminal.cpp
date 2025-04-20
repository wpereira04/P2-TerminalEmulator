////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: terminal.cpp
// Description: Contains the implementations for the terminal
// functions
//				
// Date:        04/20/2025
//
#include "terminal.h"
#include "mypipe.h"



int run_cmd(std::vector<char*> argv) {
    mypipe pipe;

    pid_t pid = fork(); // fork
    if (pid == 0) {
        // child process
        pipe.redirect(); // Redirects STDOUT
        execvp(argv[0], argv.data());
        _exit(1); // if exec fails
    }
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        std::string output = pipe.read();
        std::cout << output;
        return status;
    }
    else {
        return 1;
    }
}

void terminal_app() {
    std::string line;

    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, line);

        if (line == "exit") break;
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string word;
        while (iss >> word) tokens.push_back(word);

        std::vector<char*> argv;
        for (auto& s : tokens) argv.push_back(&s[0]);
        argv.push_back(nullptr);

        run_cmd(argv);
    }
}