/* 정수 자료형을 사용하는 프로그램*/

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	short year;			
	int sale;			
	long totalSale;	
	long long largeValue;  	
	year = 10;									// 10
	sale = 200000000;							// 200000000
	totalSale = year * sale;					// 약 21억을 넘지 않도록 주의
	printf("total sale = %d\n", totalSale);
}