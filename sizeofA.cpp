#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
       int x;
       printf("      변수 x의 크기: %d\n", sizeof(x));
       printf("     char 형의 크기: %d\n", sizeof(char));
       printf("      int 형의 크기: %d\n", sizeof(int));
       printf("    short 형의 크기: %d\n", sizeof(short));
       printf("     long 형의 크기: %d\n", sizeof(long));
       printf("long long 형의 크기: %d\n", sizeof(long long));
       printf("    float 형의 크기: %d\n", sizeof(float));
       printf("   double 형의 크기: %d\n", sizeof(double));
}