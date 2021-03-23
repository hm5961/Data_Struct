/*p2-1.c*/

#include<stdio.h>

#define MAX_SIZE 100 //상수 100을 MAX_SIZE로 정의한다.

float sum(float [], int);
// float 배열과 정수를 가지는 sum 함수를 float형으로 선언한다.
float input[MAX_SIZE], answer;
// MAX_SIZE 크기의 input 이름의 배열과 answer 이름의 변수를 float형인 전역변수로 선언한다.
int i; //i를 int형 전역변수로 선언한다.
void main(void)
{
	for(i=0; i<MAX_SIZE;  i++)
		// 전역변수 i가 MAX_SIZE(100)을 초과할 때 까지 아래줄을 반복하며 i에 1을 더한다.
		input[i] = i ; // 배열 input[i]에 i값을 저장한다.

	printf("[----- [김현민] [2018038036] -----]\n");

	/* for checking call by reference */
	printf("address of input = %p\n", input);
	// input의 값을 8자리인 16진수로 출력한다. -> 배열의 이름인 input은 배열의 시작 주소값이므로, input[0]의 주소값을 출력한다.

	answer = sum(input, MAX_SIZE);
	// sum 함수에 input배열과 MAX_SIZE를 인풋으로 할 때 나오는 리턴값을 answer에 저장한다.
	printf("The sum is: %f\n", answer); // answer의 값을 실수형으로 출력한다.
}
float sum(float list[], int n) // input배열을 list배열로, MAX_SIZE를 n으로 사용한다.
{
	printf("value of list = %p\n", list);
	// list의 값을 8자리인 16진수로 출력한다. -> 배열의 이름인 list는 배열의 시작 주소값이므로, list[0]의 주소값을 출력한다.
	printf("address of list = %p\n\n", &list);
	// list의 주소값을 8자리인 16진수로 출력한다. -> 배열의 이름인 list의 주소는 list[0]의 주소값과 같다.

	int i; // 지역변수 i를 정수형으로 선언한다.
	float tempsum = 0; // 변수 tempsum을 실수형으로 선언하고
	for(i=0; i<n; i++) // i를 0으로 초기화하고 n(MAX_SIZE)까지 아래 문장을 반복하며 i에 1을 더한다.
		tempsum += list[i]; //tempsum = tempsum + list[i]
	return tempsum; //tempsum을 반환한다.
}
