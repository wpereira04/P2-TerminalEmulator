////////////////////////////////////////////////////////
//
// ECE 3574, P2, Walter Pereira Cruz
// File name: mypipe.h
// Description: Contains the declarations for the mypipe
// functions and variables
//				
// Date:        04/20/2025
//

#ifndef MYPIPE_H
#define MYPIPE_H​
#include <array>
#include <string>
#include <vector>
#include <string>
#include <stdexcept>
#include <unistd.h>
class mypipe {
	private:
		std::array<int, 2> fd;
	public:
		mypipe();
		~mypipe();
		void redirect();
		std::string read();
};
#endif