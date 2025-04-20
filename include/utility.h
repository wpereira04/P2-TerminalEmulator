////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: utility.h
// Description: Contains the declarations for the utlity
// functions and variables
//				
// Date:        04/20/2025
//

#include <sstream>
#include <string>
#include <vector>

std::vector<char*> castArgs(const std::vector<std::string>& cmd);
// Converts a command string to a vector of words
std::vector<std::string> cmd2vec(const std::string& comm, char delimiter = ' ');