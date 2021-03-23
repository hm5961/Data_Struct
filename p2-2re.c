/*p2-2.c*/

#include<stdio.h>

void print1 (int *ptr, int rows);
//�����������ͺ��� ptr�� ���������� rows�� ���� print1 �Լ��� void������ �����Ѵ�.

int main()
{
	int one[]= {0, 1, 2, 3, 4}; // ������ ���� one�� one[0]���� ������� 0,1,2,3,4�� �����Ѵ�.


	printf("[----- [������] [2018038036] -----]\n");
	printf("one 	= %p\n", one);
	//one�� ���� 8�ڸ��� 16������ ����Ѵ�. -> �迭�� �̸��� one�� �迭�� ���� �ּҰ��̹Ƿ�, one[0]�� �ּҰ��� ����Ѵ�.
	printf("&one 	= %p\n", &one);
	//one�� �ּҰ��� 8�ڸ��� 16������ ����Ѵ�. -> �迭�� �̸��� one�� �ּҴ� �ּ��� ù �ּҰ��̶� one[0]�� �ּҰ��� ����Ѵ�.
	printf("&one[0] = %p\n", &one[0]); //one[0]�� �ּҰ��� 8�ڸ��� 16������ ����Ѵ�.
	printf("\n");

	print1(&one[0], 5); // print1�Լ��� &one[0]�� 5�� ��ǲ�Ѵ�.

	return 0;
}

void print1 (int *ptr, int rows)
{
	/* print out a one-dimensional array using a pointer*/
	int i;
	printf("Address \t Contents\n");
	for(i=0;i<rows;i++)
		printf("%p \t %5d\n", ptr+i, *(ptr+i));
	// ptr[i]�� �ּҰ�(ptr+i)�� 8�ڸ��� 16������, ptr[i](*ptr+i)�� �տ� 5��ŭ�� ��ĭ�� ���� ���������� ����� ���� ����Ѵ�.
	printf("\n");
}
