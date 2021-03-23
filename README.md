/* ap1.c */

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int list[5]; //5개의 요소를 저장하는 1차원 배열 list를 정수형으로 선언한다.
	int *plist[5] = {NULL, };
	//5개의 요소를 저장하는 1차원 배열 plist를 정수형 포인터로 선언하고 NULL로 초기화한다.

	plist[0] = (int*)malloc(sizeof(int));
	/*plist[0]에 int 만큼의 크기(4바이트)만큼 동적 메모리 할당한다. -> 4바이트만큼 heap 영역에서 메모리 공간을 생성하고 그 주소를 plist[0]에 저장한다.*/

	list[0] = 1; //list[0]에 1을 저장한다.
	list[1] = 100; // list[1]에 100을 저장한다.

	*plist[0] = 200; //plist[0]이 역참조하는 위치(heap영역의 주소)에 200을 저장한다.
	printf("[----- [김현민] [2018038036] -----]\n");

	printf("value of list[0] 		= %d\n", list[0]);
	//list[0]에 저장된 값을 정수형으로 출력한다.
	printf("address of list[0]		= %p\n", &list[0]);
	//list[0]의 주소값을 8자리인 16진수로 출력한다.
	printf("value of list 			= %p\n", list);
	//list의 값을 8자리인 16진수로 출력한다. -> 배열 list의 첫번째 주소값인 list[0]이 출력된다.
	printf("address of list (&list)		= %p\n", &list);
	//list의 주소값을 8자리인 16진수로 출력한다. -> 배열 list의 위치를 나타내는 list[0]이 출력된다.


	printf("-------------------------------------------\n\n");
	printf("value of list[1] 		= %d\n", list[1]);
	//list[1]에 저장된 값을 정수형으로 출력한다.
	printf("address of list[1]		= %p\n", &list[1]);
	//list[1]의 주소값을 8자리인 16진수로 출력한다.
	printf("value of *(list+1) 		= %d\n", *(list+1));
	/*list+1의 역참조값을 정수형으로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]을 나타내고, +1로 인해 다음 자리(정수형이라 4바이트 추가된 주소)의 역참조 값이 출력된다. -> list[1]에 저장된 값이 출력된다.
	*/
	printf("address of list+1		= %p\n", list+1);
	//list+1의 주소값을 8자리인 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값인 list[0]을 나타내고, +1로 인해 다음 자리(정수형이라 4바이트 추가된 주소)의 주소값이 출력된다. -> list[1]의 주소값이 출력된다.


	printf("-------------------------------------------\n\n");
	printf("value of *plist[0] 		= %d\n", *plist[0]);
	//plist[0]이 역참조값을 정수형으로 출력한다. -> plist[0]이 가르키는 주소에 저장된 값을 출력한다.
	printf("&plist[0]			= %p\n", &plist[0]);
	// plist[0]의 주소값을 정수형으로 출력한다.
	printf("&plist			 	= %p\n", &plist);
	// plist의 주소값을 8자리인 16진수로 출력한다. -> 배열 plist의 첫번째 주소값인 plist[0]이 출력된다.
	printf("plist			 	= %p\n", plist);
	// plist의 값을 8자리인 16진수로 출력한다. -> 배열의 이름인 plist는 배열의 시작 주소값이므로, plist[0]의 주소값을 출력한다.
	printf("plist[0]		 	= %p\n", plist[0]);
	// plist[0]의 값을 8자리인 16진수로 출력한다. -> 저장된 heap 영역의 주소가 출력된다.
	printf("plist[1]		 	= %p\n", plist[1]);
	// plist[1]의 값을 8자리인 16진수로 출력한다. -> 초기화 되어서 0을 출력한다.
	printf("plist[2]		 	= %p\n", plist[2]);
	// plist[2]의 값을 8자리인 16진수로 출력한다. -> 초기화 되어서 0을 출력한다.
	printf("plist[3]			= %p\n", plist[3]);
	// plist[3]의 값을 8자리인 16진수로 출력한다. -> 초기화 되어서 0을 출력한다.
	printf("plist[4]			= %p\n", plist[4]);
	// plist[4]의 값을 8자리인 16진수로 출력한다. -> 초기화 되어서 0을 출력한다.

	free(plist[0]); // 할당된 heap영역의 메모리를 해제한다.
}
