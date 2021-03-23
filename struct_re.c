/* struct.c */
#include<stdio.h>

struct student1{ //아래의 변수들을 멤버로 가진 구조체 student1을 정의한다
	char lastName;
	int studentId;
	char grade;
};

typedef struct { //아래의 변수들을 멤버로 가진 구조체 student2을 정의한다
	char lastName;
	 int studentId;
	 char grade;
} student2; //typedef로 정의되었기에 student2는

int main()
{

	printf("[----- [김현민] [2018038036] -----]\n");

	struct student1 st1 = {'A', 100, 'A'};
	//구조체 student1을 이용해 st1을 만들고 그 구조체에 순서에 맞는 값을 저장한다.

	printf("st1.lastName = %c\n", st1.lastName);
	printf("st1.studentId = %d\n", st1.studentId);
	printf("st1.grade = %c\n", st1.grade);


	student2 st2 = {'B', 200, 'B'};
	//구조체 student2를 이용해 st2를 만들고 그 구조체에 순서에 맞는 값을 저장한다. -> typedef로 정의되어 struct 형태를 알리기위해 struct를 작성할 필요가 없다

	printf("\nst2.lastName = %c\n", st2.lastName);
	printf("st2.studentId = %d\n", st2.studentId);
	printf("st2.grade = %c\n", st2.grade);

	student2 st3; //student2타입을 가진 st3를 선언한다.

	st3 = st2; // st2에 저장된 값을 st3에 저장한다. -> 같은 타입이라 가능하다.

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
	//컴파일러로 구동불가

	return 0;
}
