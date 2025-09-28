#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int x = 10;					// 십진수 10
	int y = 010;				// 팔진수 10
	int z = 0x10;				// 16진수 10
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
}