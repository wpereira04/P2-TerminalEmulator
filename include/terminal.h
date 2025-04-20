////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: terminal.h
// Description: Contains the declarations for the terminal
// functions and variables
//				
// Date:        04/20/2025
//
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
// run_cmd:
int run_cmd(std::vector<char*> argv);

// terminal_app:

void terminal_app();