#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	float x = 1.23456e-38;		// 1.23456x10^-38
	float y = 1.23456e-40;		// 1.23456x10^-40
	float z = 1.23456e-46;		// 1.23456x10^-46
	printf("x = %e\n", x);
	printf("y = %e\n", y);
	printf("z = %e\n", z);
}
