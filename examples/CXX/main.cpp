#include <iostream> 
#include "build_number.hpp"

int main()
{ 
	std::cout << "Build number is: " << BUILD_NUMBER << std::endl;
	
	//Just for keeping the console open
	std::cin.get();
	return 0; 
}
