/* padding.c */
#include <stdio.h>

struct student{ //�Ʒ��� �������� ����� ���� ����ü student�� �����Ѵ�.
	char lastName[13]; //char ���� 13�� -> 1*13 ����Ʈ -> �е��� �Ǿ� 16����Ʈ
	int studentId; // int ���� 1�� -> 4*1����Ʈ -> 4����Ʈ
	short grade; // short ���� 1�� -> 2*1����Ʈ -> �е��� �Ǿ� 4����Ʈ
};

int main()
{
	struct student pst; //����ü ������ �����Ѵ�.

	printf("[----- [������] [2018038036] -----]\n");

	printf("size of student = %ld\n", sizeof(struct student)); //���� ����ü�� �� ũ���� 24�� ��µ�.
	printf("size of int = %ld\n", sizeof(int)); //int�� ũ���� 4����Ʈ�� ��µ�
	printf("size of short = %ld\n", sizeof(short)); //short�� ũ���� 2����Ʈ�� ��µ�

	return 0;
}
