#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	char code = 'A';								// A를 문자 상수로
	printf("%d %d %d\n", code, code+1, code+2);		// 65 66 67이 출력된다.
	printf("%c %c %c\n", code, code+1, code+2);		// A B C가 출력된다. 
}