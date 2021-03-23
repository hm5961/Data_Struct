/*p2-2.c*/

#include<stdio.h>

void print1 (int *ptr, int rows);
//정수형포인터변수 ptr과 정수형변수 rows룰 가진 print1 함수를 void형으로 선언한다.

int main()
{
	int one[]= {0, 1, 2, 3, 4}; // 정수형 변수 one에 one[0]부터 순서대로 0,1,2,3,4를 저장한다.


	printf("[----- [김현민] [2018038036] -----]\n");
	printf("one 	= %p\n", one);
	//one의 값을 8자리인 16진수로 출력한다. -> 배열의 이름인 one은 배열의 시작 주소값이므로, one[0]의 주소값을 출력한다.
	printf("&one 	= %p\n", &one);
	//one의 주소값을 8자리인 16진수로 출력한다. -> 배열의 이름인 one의 주소는 주소의 첫 주소값이라 one[0]의 주소값을 출력한다.
	printf("&one[0] = %p\n", &one[0]); //one[0]의 주소값을 8자리인 16진수로 출력한다.
	printf("\n");

	print1(&one[0], 5); // print1함수에 &one[0]과 5를 인풋한다.

	return 0;
}

void print1 (int *ptr, int rows)
{
	/* print out a one-dimensional array using a pointer*/
	int i;
	printf("Address \t Contents\n");
	for(i=0;i<rows;i++)
		printf("%p \t %5d\n", ptr+i, *(ptr+i));
	// ptr[i]의 주소값(ptr+i)을 8자리인 16진수로, ptr[i](*ptr+i)를 앞에 5만큼의 빈칸을 지닌 정수형으로 저장된 값을 출력한다.
	printf("\n");
}
