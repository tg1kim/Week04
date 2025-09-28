#include <stdio.h>
#include <limits.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	short shrtMoney = SHRT_MAX;				// 최대값 SHRT_MAX로 초기화한다.
	unsigned short unsgMoney = USHRT_MAX; 	// 최대값 USHRT_MAX로 초기화한다.
	
	shrtMoney = shrtMoney + 1;				// 1 증가
	printf("shrtMoney = %d\n", shrtMoney);
	
	unsgMoney = unsgMoney + 1;				// 1 증가
	printf("unsgMoney = %d\n", unsgMoney);
}