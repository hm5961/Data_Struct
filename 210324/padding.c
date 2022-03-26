/* padding.c */
#include <stdio.h>

struct student{ //아래의 변수들을 멤버로 가진 구조체 student를 정의한다.
	char lastName[13]; //char 형이 13개 -> 1*13 바이트 -> 패딩이 되어 16바이트
	int studentId; // int 형이 1개 -> 4*1바이트 -> 4바이트
	short grade; // short 형이 1개 -> 2*1바이트 -> 패딩이 되어 4바이트
};

int main()
{
	struct student pst; //구조체 변수를 선언한다.

	printf("[----- [김현민] [2018038036] -----]\n");

	printf("size of student = %ld\n", sizeof(struct student)); //위의 구조체의 총 크기인 24가 출력됨.
	printf("size of int = %ld\n", sizeof(int)); //int의 크기인 4바이트가 출력됨
	printf("size of short = %ld\n", sizeof(short)); //short의 크기인 2바이트가 출력됨

	return 0;
}
