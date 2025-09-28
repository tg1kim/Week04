#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int x, y, z, sum;
	sum = 0;
	printf("3개의 정수를 입력하세요 (x, y, z): ");
	scanf("%d %d %d", &x, &y, &z);				// x, y, z에 입력
	sum += x;									// sum에 x를 더한다
	sum += y;									// sum에 y를 더한다
	sum += z;									// sum에 z를 더한다
	printf("3개 정수의 합은 %d\n", sum);
}