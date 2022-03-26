#include <stdio.h>

void main(){
    char charType; //charType�� ������ ������ char�� �����Ѵ�.
    int integerType; //integerType�� ������ ������ int�μ����Ѵ�.
    float floatType; // floatType�� �Ǽ��� ������ float�� �����Ѵ�.
    double doubleType;  // doubleType�� �Ǽ��� ������ double�� �����Ѵ�.

    printf("[----- [������] [2018038036] -----] \n\n");

    printf("Size of char : %ld byte \n",sizeof(charType)); //charType�� �ڷ����� char�� ũ�⸦ ���������� ����Ѵ�. -> 1����Ʈ�� ��µ�. 
    printf("Size of int : %ld bytes \n",sizeof(integerType)); //integerType�� �ڷ����� int�� ũ�⸦ ���������� ����Ѵ�. -> 4����Ʈ�� ��µ�. 
    printf("Size of float : %ld bytes \n",sizeof(floatType)); //fliatType�� �ڷ����� float�� ũ�⸦ ���������� ����Ѵ�. -> 4����Ʈ�� ��µ�. 
    printf("Size of double : %ld bytes \n",sizeof(doubleType)); //doubleType�� �ڷ����� double�� ũ�⸦ ���������� ����Ѵ�. -> 8����Ʈ�� ��µ�. 

    printf("-----------------------------------------\n");

    printf("Size of char : %ld byte \n",sizeof(char)); // char�� ũ�⸦ ���������� ����Ѵ�. -> 1����Ʈ�� ��µ�. 
    printf("Size of int : %ld bytes \n",sizeof(int)); // int�� ũ�⸦ ���������� ����Ѵ�. -> 4����Ʈ�� ��µ�. 
    printf("Size of float : %ld bytes \n",sizeof(float)); // float�� ũ�⸦ ���������� ����Ѵ�. -> 4����Ʈ�� ��µ�. 
    printf("Size of double : %ld bytes \n",sizeof(double)); // double�� ũ�⸦ ���������� ����Ѵ�. -> 8����Ʈ�� ��µ�. 

    printf("-----------------------------------------\n");

    printf("Size of char* : %ld byte \n",sizeof(char*)); //char�� ���� ����� ��ġ(�ּ�)�� ���������� ����Ѵ�. -> 64��Ʈ �ü���̳� gdb�� 32��Ʈ�̹Ƿ� 4����Ʈ�� ��µ�. 
    printf("Size of int* : %ld bytes \n",sizeof(int*)); //int�� ���� ����� ��ġ(�ּ�)�� ���������� ����Ѵ�. -> 64��Ʈ �ü���̳� gdb�� 32��Ʈ�̹Ƿ� 4����Ʈ�� ��µ�.
    printf("Size of float* : %ld bytes \n",sizeof(float*)); //float�� ���� ����� ��ġ(�ּ�)�� ���������� ����Ѵ�. -> 64��Ʈ �ü���̳� gdb�� 32��Ʈ�̹Ƿ� 4����Ʈ�� ��µ�.
    printf("Size of double* : %ld bytes \n",sizeof(double*)); //double�� ���� ����� ��ġ(�ּ�)�� ���������� ����Ѵ�. -> 64��Ʈ �ü���̳� gdb�� 32��Ʈ�̹Ƿ� 4����Ʈ�� ��µ�.
}
