/* ap2.c*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int list[5]; //5개의 요소를 저장하는 1차원 배열 list를 정수형으로 선언한다.
	int *plist[5]; //5개의 요소를 저장하는 1차원 배열 plist를 정수형 포인터로 선언한다.

	list[0] = 10; //list[0]에 10을 저장한다.
	list[1] = 11; //list[1]에 11을 저장한다.

	plist[0] = (int*)malloc(sizeof(int));
	/*plist[0]에 int 만큼의 크기(4바이트)만큼 동적 메모리 할당한다. -> 4바이트만큼 heap 영역에서 메모리 공간을 생성하고 그 주소를 plist[0]에 저장한다.*/
	printf("[----- [김현민] [2018038036] -----]\n");

	printf("list[0] \t = %d\n", list[0]); // list[0]의 값을 정수형으로 출력한다.
	printf("address of list \t = %p\n", list);
	// list의 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 주소를 출력한다.
	printf("address of list[0] \t = %p\n", &list[0]);
	// list[0]의 주소를 8자리 16진수로 출력한다.
	printf("address of list + 0 \t = %p\n", list+0);
	// list의 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 주소를 출력한다.
	printf("address of list + 1 \t = %p\n", list+1);
	/* list의 다음 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 4바이트 뒤에 있는 주소값의 주소를 출력한다. -> list[1]을 출력한다.*/
	printf("address of list + 2 \t = %p\n", list+2);
	/* list의 다음 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 4*2바이트 뒤에 있는 주소값의 주소를 출력한다. -> list[2]를 출력한다.*/
	printf("address of list + 3 \t = %p\n", list+3);
	/* list의 다음 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 4*2바이트 뒤에 있는 주소값의 주소를 출력한다. -> list[3]을 출력한다.*/
	printf("address of list + 4 \t = %p\n", list+4);
	/* list의 다음 주소를 8자리 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]의 4*2바이트 뒤에 있는 주소값의 주소를 출력한다. -> list[4]를 출력한다.*/
	printf("address of list[4] \t = %p\n", &list[4]);
	// list[4]의 주소를 8자리 16진수로 출력한다.

	free(plist[0]); // 할당된 heap영역의 메모리를 해제한다.
}
