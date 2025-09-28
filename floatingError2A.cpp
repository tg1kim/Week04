#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	double x;
	x = (1.0e20 + 5.0) - 1.0e20; 		// 1.0x10^20 + 5.0 - 1.0x10^20
	printf("%f\n",x);
}
