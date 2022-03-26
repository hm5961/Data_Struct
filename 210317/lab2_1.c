#include <stdio.h>

void main(){
    char charType; //charType을 문자형 변수인 char로 선언한다.
    int integerType; //integerType을 정수형 변수인 int로선언한다.
    float floatType; // floatType을 실수형 변수인 float로 선언한다.
    double doubleType;  // doubleType을 실수형 변수인 double로 선언한다.

    printf("[----- [김현민] [2018038036] -----] \n\n");

    printf("Size of char : %ld byte \n",sizeof(charType)); //charType의 자료형인 char의 크기를 정수형으로 출력한다. -> 1바이트가 출력됨. 
    printf("Size of int : %ld bytes \n",sizeof(integerType)); //integerType의 자료형인 int의 크기를 정슈형으로 출력한다. -> 4바이트가 출력됨. 
    printf("Size of float : %ld bytes \n",sizeof(floatType)); //fliatType의 자료형인 float의 크기를 정수형으로 출력한다. -> 4바이트가 출력됨. 
    printf("Size of double : %ld bytes \n",sizeof(doubleType)); //doubleType의 자료형인 double의 크기를 정수형으로 출력한다. -> 8바이트가 출력됨. 

    printf("-----------------------------------------\n");

    printf("Size of char : %ld byte \n",sizeof(char)); // char의 크기를 정수형으로 출력한다. -> 1바이트가 출력됨. 
    printf("Size of int : %ld bytes \n",sizeof(int)); // int의 크기를 정수형으로 출력한다. -> 4바이트가 출력됨. 
    printf("Size of float : %ld bytes \n",sizeof(float)); // float의 크기를 정수형으로 출력한다. -> 4바이트가 출력됨. 
    printf("Size of double : %ld bytes \n",sizeof(double)); // double의 크기를 정수형으로 출력한다. -> 8바이트가 출력됨. 

    printf("-----------------------------------------\n");

    printf("Size of char* : %ld byte \n",sizeof(char*)); //char의 값이 저장된 위치(주소)를 정수형으로 출력한다. -> 64비트 운영체제이나 gdb가 32비트이므로 4바이트가 출력됨. 
    printf("Size of int* : %ld bytes \n",sizeof(int*)); //int의 값이 저장된 위치(주소)를 정수형으로 출력한다. -> 64비트 운영체제이나 gdb가 32비트이므로 4바이트가 출력됨.
    printf("Size of float* : %ld bytes \n",sizeof(float*)); //float의 값이 저장된 위치(주소)를 정수형으로 출력한다. -> 64비트 운영체제이나 gdb가 32비트이므로 4바이트가 출력됨.
    printf("Size of double* : %ld bytes \n",sizeof(double*)); //double의 값이 저장된 위치(주소)를 정수형으로 출력한다. -> 64비트 운영체제이나 gdb가 32비트이므로 4바이트가 출력됨.
}
