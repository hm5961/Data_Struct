/*p2-2.c*/

#include<stdio.h>

void print1 (int *ptr, int rows);
//정수형포인터변수 ptr과 정수형변수 rows룰 가진 print1 함수를 void형으로 선언한다.

int main()
{
	int one[]= {0, 1, 2, 3, 4}; // 정수형 변수 one에


	printf("[----- [김현민] [2018038036] -----]\n");
	printf("12 %d \n", one[1]);
	printf("one 	= %p\n", one);
	printf("&one 	= %p\n", &one);
	printf("&one[0] = %p\n", &one[0]);
	printf("\n");

	print1(&one[0], 5);

	return 0;
}

void print1 (int *ptr, int rows)
{
	/* print out a one-dimensional array using a pointer*/
	int i;
	printf("Address \t Contents\n");
	for(i=0;i<rows;i++)
		printf("%p \t %5d\n", ptr+i, *(ptr+i));
	printf("\n");
}
