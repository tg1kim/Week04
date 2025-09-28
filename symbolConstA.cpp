#include <stdio.h>

#define TAX_RATE  0.2									// 세율 0.2로 정의

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	const int MONTHS = 12;								// 상수 12로 정의
	int mnthSalary, yearSalary;							// 변수 선언
	printf("월급을 입력하시요: ");							// 입력 안내문
	scanf("%d", &mnthSalary);							// mnthSalary에 입력
	yearSalary = MONTHS * mnthSalary;					// 순수입 계산
	printf("연봉은 %d입니다.\n", yearSalary);
	printf("세금은 %f입니다.\n", yearSalary * TAX_RATE);
}