#include <stdio.h>
void main(){
	
	int i, *p; // 변수 i를 정수형으로, 변수 p를 포인터로 선언
    i = 10; // 변수 i에 상수 10을 저장 

    printf("value of i = %d\n", i);  //i에 저장한 값을 정수형으로 출력   
    printf("address of i = %p\n", &i);  //i에 주소값을 정수형으로 출력 
    printf("value of p = %p\n", p); // p에 저장한 임의의 값을 16진수로 출력 
    printf("address of p = %p\n", &p); // p의 주소값을 16진수로 출력 

    p = &i; //변수 p에 i의 주소값 저장 

    printf("\n\n----- after p = &i ------------\n\n"); //출력 시 줄구분 

    printf("value of p = %p\n", p); //p의 값 출력 => i의 주소값을 16진수로 출력 
    printf("address of p = %p\n", &p); // p의 주소값을 16진수로 출력 => 변동 없음 
    printf("dereferencing *p = %d\n", *p); // 포인터 p의 역참조를 정수형으로 출력 => 10
}
