/*
 ============================================================================
 Name        : lab2_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main()
{
	int i; //i를 정수형 변수로 선언
	int *ptr;//ptr을 포인터로 선언
	int **dptr;//dptr을 이중포인터로 선언
	i = 1234;//변수 i에 상수 1234를 저장

	printf("[----- [김현민] [2018038036] -----]\n\n"); //내 이름과 학번을 출력한다.

	printf("[checking values before ptr = &i] \n");
	printf("value of i == %d\n", i); //i에 저장된 값을 정수형으로 출력 -> 저장된 1234가 출력됨.
	printf("address of i == %p\n", &i); //i의 주소를 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> i가 저장된 주소가 0061FF1C로 출력됨.
	printf("value of ptr == %p\n", ptr); // ptr의 값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> ptr에 저장된 임의의 값인 00208000로 출력됨.
	printf("address of ptr == %p\n", &ptr); //ptr의 주소를 포인터 주소값으로 출력(8자리인 16진수로 출력) -> ptr이 저장된 주소인 0061FF18로 출력됨.

	ptr = &i; /* ptr is now holding the address of i */ //ptr에 i의 주소값을 저장한다.

	printf("\n[checking values after ptr = &i] \n");
	printf("value of i == %d\n", i); // i에 저장된 값을 정수형으로 출력 -> 저장된 1234가 출력됨.
	printf("address of i == %p\n", &i); // i의 주소를 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> i가 저장된 주소인 0061FF1C로 출력됨.
	printf("value of ptr == %p\n", ptr); // ptr의 값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> 앞서 ptr에 i의 주소값을 저장했기에 i의 주솟값과 같은 0061FF1C로 출력됨.
	printf("address of ptr == %p\n", &ptr); // ptr의 주소를 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> ptr이 저장된 주소는 바뀌지 않았기에 그대로 0061FF18로 출력됨.
	printf("value of *ptr == %d\n", *ptr); // ptr의 역참조 값을 정수형으로 출력 -> ptr에 저장된 값인 0061FF61C에 저장된 값인(i에 저장된 값인) 1234가 출력됨.

	dptr = &ptr; /* dptr is now holding the address of ptr */ //dptr에 ptr의 주소값을 저장한다.

	printf("\n[checking values after dptr = &ptr] \n");
	printf("value of i == %d\n", i); // i에 저장된 값을 정수형으로 출력 -> 저장된 1234가 출력됨.
	printf("address of i == %p\n", &i); // i의 주소를 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> i가 저장된 주소인 0061FF1C로 출력됨.
	printf("value of ptr == %p\n", ptr); // ptr의 값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> ptr에 저장된 값인 00208000으로 출력됨.
	printf("address of ptr == %p\n", &ptr); // ptr의 주소를 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> ptr이 저장된 주소인 0061FF18이 출력됨.
	printf("value of *ptr == %d\n", *ptr); // ptr의 역참조 값을 정수형으로 출력 -> ptr에 저장된 값인 0061FF61C에 저장된 값인(i에 저장된 값인) 1234가 출력됨.
	printf("value of dptr == %p\n", dptr); // dptr의 값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> dptr에 저장된 값인(ptr의 주소) 0061FF18이 출력됨.
	printf("address of ptr == %p\n", &dptr); // dptr의 주소값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> dptr에 주소값인 0061FF14가 출력됨.
	printf("value of *dptr == %p\n", *dptr); //dptr의 역참조 값을 포인터의 주소값으로 출력(8자리인 16진수로 출력) -> dptr에 저장된 값인(tpr의 주소값) 0061FF1C가 출력됨.
	printf("value of **dptr == %d\n", **dptr); //dptr을 두 번 역참조 시킨 값을 정수형으로 출력 -> dptr에 저장된 값인(tpr의 주소)가 나타내는 값(tpr의 값)이 나타내는 값(i의 주소)에 저장된 1234가 출력됨.

	*ptr = 7777; /* changing the value of *ptr */ //포인터 ptr에 7777을 저장 -> ptr에 저장된 값(i의 주소)이 나타내는 곳에 있는 값에(i에) 7777을 저장

	printf("\n[after *ptr = 7777] \n");
	printf("value of i == %d\n", i); // i에 저장된 값을 정수형으로 출력 -> 저장된 7777이 출력됨
	printf("value of *ptr == %d\n", *ptr); // 포인터 ptr에 값을 정수형으로 출력 -> ptr에 저장된 값(i의 주소)이 나타내는 곳에 있는 값(i)에 저장된 7777을 출력
	printf("value of **dptr == %d\n", **dptr); // 이중포인터 dptr에 값을 정수형으로 출력 -> dptr에 저장된 값(ptr의 주소)이 나타내는 곳에 있는 값(ptr의 값 / i의 주소)가 나타내는 곳에 있는 값(i의 값)에 저장된 7777을 출력

	**dptr = 8888; /* changing the value of **dptr */ // 이중포인터 dptr에 8888을 저장 -> dptr에 저장된 값(ptr의 주소)이 나타내는 곳에 있는 값(ptr의 값 / i의 주소)가 나타내는 곳에 있는 값(i의 값)에 8888을 저장

	printf("\n[after **dptr = 8888] \n");
	printf("value of i == %d\n", i); // i에 저장된 값을 정수형으로 출력 -> 저장된 8888이 출력
	printf("value of *ptr == %d\n", *ptr); // 포인터 ptr에 저장된 값을 정수형으로 출력 -> ptr에 저장된 값(i의 주소)이 나타내는 곳에 있는 값(i의 값)에 저장된 8888을 출력
	printf("value of **dptr == %d\n", **dptr); // 이중포인터 dptr에 저장된 값을 정수형으로 출력 -> dptr에 저장된 값(ptr의 주소)가 나타내는 곳에 있는 값(ptr의 값 / i의 주소)이 나타내는 값(i의 값)인 8888을 출력
	return 0;
}
