/* struct.c */
#include<stdio.h>

struct student1{ //�Ʒ��� �������� ����� ���� ����ü student1�� �����Ѵ�
	char lastName;
	int studentId;
	char grade;
};

typedef struct { //�Ʒ��� �������� ����� ���� ����ü student2�� �����Ѵ�
	char lastName;
	 int studentId;
	 char grade;
} student2; //typedef�� ���ǵǾ��⿡ student2��

int main()
{

	printf("[----- [������] [2018038036] -----]\n");

	struct student1 st1 = {'A', 100, 'A'};
	//����ü student1�� �̿��� st1�� ����� �� ����ü�� ������ �´� ���� �����Ѵ�.

	printf("st1.lastName = %c\n", st1.lastName);
	printf("st1.studentId = %d\n", st1.studentId);
	printf("st1.grade = %c\n", st1.grade);


	student2 st2 = {'B', 200, 'B'};
	//����ü student2�� �̿��� st2�� ����� �� ����ü�� ������ �´� ���� �����Ѵ�. -> typedef�� ���ǵǾ� struct ���¸� �˸������� struct�� �ۼ��� �ʿ䰡 ����

	printf("\nst2.lastName = %c\n", st2.lastName);
	printf("st2.studentId = %d\n", st2.studentId);
	printf("st2.grade = %c\n", st2.grade);

	student2 st3; //student2Ÿ���� ���� st3�� �����Ѵ�.

	st3 = st2; // st2�� ����� ���� st3�� �����Ѵ�. -> ���� Ÿ���̶� �����ϴ�.

	printf("\nst3.lastName = %c\n", st3.lastName);
	printf("st3.studentId = %d\n", st3.studentId);
	printf("st3.grade = %c\n", st3.grade);

	/* equality test */
	/*
	if(st3 == st2)
		printf("equal\n");
	else
		printf("not equal\n");
	*/
	//�����Ϸ��� �����Ұ�

	return 0;
}
