////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: utility.cpp
// Description: Contains the implementations for the utility
// functions
//				
// Date:        04/20/2025
//

#include "utility.h"

std::vector<char*> castArgs(const std::vector<std::string>& cmd) {
    std::vector<char*> args;
    // for each
    for (const std::string& s : cmd) {
        args.push_back(const_cast<char*>(s.c_str()));
    }
    args.push_back(nullptr);
    return args;
}

std::vector<std::string> cmd2vec(const std::string& comm, char delimiter) {
    std::istringstream iss(comm);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}