#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	float value = 0.1;			// 0.1
	printf("%.20f\n", value);	// %.20f는 소수점 이하를 20자리로 출력하라는 의미이다.
}