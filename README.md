/*size.c*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int **x;

	printf("[----- [김현민] [2018038036] -----]\n");
	printf("sizeof(x) = %lu\n", sizeof(x));
	// 32비트 컴파일러로 작동되기에 주소의 크기인 4바이트가 출력됨.
	printf("sizeof(*x) = %lu\n", sizeof(*x));
	// x가 가르키는 주소에 저장된 값이 주소라 주소의 크기인 4바이트가 출력됨.
	printf("sizeof(**x) = %lu\n", sizeof(**x));
	// *x가 가르키는 값에 있는 주소에 있는 값은 int형으로 저장되어 4바이트가 출력됨.
}
