/*size.c*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int **x;

	printf("[----- [������] [2018038036] -----]\n");
	printf("sizeof(x) = %lu\n", sizeof(x));
	// 32��Ʈ �����Ϸ��� �۵��Ǳ⿡ �ּ��� ũ���� 4����Ʈ�� ��µ�.
	printf("sizeof(*x) = %lu\n", sizeof(*x));
	// x�� ����Ű�� �ּҿ� ����� ���� �ּҶ� �ּ��� ũ���� 4����Ʈ�� ��µ�.
	printf("sizeof(**x) = %lu\n", sizeof(**x));
	// *x�� ����Ű�� ���� �ִ� �ּҿ� �ִ� ���� int������ ����Ǿ� 4����Ʈ�� ��µ�.
}
