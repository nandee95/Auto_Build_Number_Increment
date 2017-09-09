#include <iostream> 
#include "build_number.hpp"

int main()
{ 
	std::cout << "Build number is: " << BUILD_NUMBER << std::endl;
	
	//Just for keeping the console open
	int t;
	std::cin>>t;
	return 0; 
}