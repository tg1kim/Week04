/* 부동 소수점 자료형의 크기 계산*/

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	float x = 1.234567890123456789;					// 1.2~90~9
	double y = 1.234567890123456789;				// 1.2~90~9
	printf(" float의 크기 = %d\n", sizeof(float));
	printf("double의 크기 = %d\n", sizeof(double));
	printf("x = %30.25f\n", x);
	printf("y = %30.25f\n", y);
}
