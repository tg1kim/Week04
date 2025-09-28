#include <stdio.h>

#pragma warning(disable: )

void main()
{
	double lightSpeed = 300000; 					// 빛의 속도를 저장하는 변수(300000km/sec)
	double distance = 149600000;					// 거리 변수에 149600000km로 초기화한다. 
	double time;									// 시간을 나타내는 변수
	time = distance / lightSpeed;					// 거리를 빛의 속도로 나눈다.
	time = time / 60.0;								// 초를 분으로 변환한다. 
	printf("빛의 속도는 %f km/s\n", lightSpeed);
	printf("태양과 지구와의 거리 %f km\n", distance);
	printf("도달 시간은 %f 분\n", time);				// 시간을 출력한다. 
}