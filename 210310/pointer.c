#include <stdio.h>
void main(){
	
	int i, *p; // ���� i�� ����������, ���� p�� �����ͷ� ����
    i = 10; // ���� i�� ��� 10�� ���� 

    printf("value of i = %d\n", i);  //i�� ������ ���� ���������� ���   
    printf("address of i = %p\n", &i);  //i�� �ּҰ��� ���������� ��� 
    printf("value of p = %p\n", p); // p�� ������ ������ ���� 16������ ��� 
    printf("address of p = %p\n", &p); // p�� �ּҰ��� 16������ ��� 

    p = &i; //���� p�� i�� �ּҰ� ���� 

    printf("\n\n----- after p = &i ------------\n\n"); //��� �� �ٱ��� 

    printf("value of p = %p\n", p); //p�� �� ��� => i�� �ּҰ��� 16������ ��� 
    printf("address of p = %p\n", &p); // p�� �ּҰ��� 16������ ��� => ���� ���� 
    printf("dereferencing *p = %d\n", *p); // ������ p�� �������� ���������� ��� => 10
}
