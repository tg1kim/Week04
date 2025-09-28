/* 원의 면적을 계산하는 프로그램*/

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	float radius;						// 원의 반지름
	float area;							// 원의 면적
	printf("원의 반지름을 입력하시요: ");
	scanf("%f", &radius);				// radius에 입력
	area = 3.141592 * radius * radius;	// PI = 3.141592
	printf("원의 면적: %f\n", area);
}