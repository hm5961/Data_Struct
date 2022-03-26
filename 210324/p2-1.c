/*p2-1.c*/

#include<stdio.h>

#define MAX_SIZE 100 //��� 100�� MAX_SIZE�� �����Ѵ�.

float sum(float [], int);
// float �迭�� ������ ������ sum �Լ��� float������ �����Ѵ�.
float input[MAX_SIZE], answer;
// MAX_SIZE ũ���� input �̸��� �迭�� answer �̸��� ������ float���� ���������� �����Ѵ�.
int i; //i�� int�� ���������� �����Ѵ�.
void main(void)
{
	for(i=0; i<MAX_SIZE;  i++)
		// �������� i�� MAX_SIZE(100)�� �ʰ��� �� ���� �Ʒ����� �ݺ��ϸ� i�� 1�� ���Ѵ�.
		input[i] = i ; // �迭 input[i]�� i���� �����Ѵ�.

	printf("[----- [������] [2018038036] -----]\n");

	/* for checking call by reference */
	printf("address of input = %p\n", input);
	// input�� ���� 8�ڸ��� 16������ ����Ѵ�. -> �迭�� �̸��� input�� �迭�� ���� �ּҰ��̹Ƿ�, input[0]�� �ּҰ��� ����Ѵ�.

	answer = sum(input, MAX_SIZE);
	// sum �Լ��� input�迭�� MAX_SIZE�� ��ǲ���� �� �� ������ ���ϰ��� answer�� �����Ѵ�.
	printf("The sum is: %f\n", answer); // answer�� ���� �Ǽ������� ����Ѵ�.
}
float sum(float list[], int n) // input�迭�� list�迭��, MAX_SIZE�� n���� ����Ѵ�.
{
	printf("value of list = %p\n", list);
	// list�� ���� 8�ڸ��� 16������ ����Ѵ�. -> �迭�� �̸��� list�� �迭�� ���� �ּҰ��̹Ƿ�, list[0]�� �ּҰ��� ����Ѵ�.
	printf("address of list = %p\n\n", &list);
	// list�� �ּҰ��� 8�ڸ��� 16������ ����Ѵ�. -> �迭�� �̸��� list�� �ּҴ� list[0]�� �ּҰ��� ����.

	int i; // �������� i�� ���������� �����Ѵ�.
	float tempsum = 0; // ���� tempsum�� �Ǽ������� �����ϰ�
	for(i=0; i<n; i++) // i�� 0���� �ʱ�ȭ�ϰ� n(MAX_SIZE)���� �Ʒ� ������ �ݺ��ϸ� i�� 1�� ���Ѵ�.
		tempsum += list[i]; //tempsum = tempsum + list[i]
	return tempsum; //tempsum�� ��ȯ�Ѵ�.
}
