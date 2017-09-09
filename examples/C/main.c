#include <stdio.h>
#include "build_number.h"

int main()
{ 
	printf("Build number is: %d", BUILD_NUMBER);

	//Just for keeping the console open
	int a = 0;
	scanf("%d",&a);
	return 0; 
}