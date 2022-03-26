/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4 // 최대 크기로 사용될 상수 선언  

typedef char element; // 배열에 요소로 들어갈 문자형 변수 선언 
typedef struct { // 선언된 상수 크기의 큐 배열과 큐 연산을 위한 정수형 변수를 구조체로 선언 
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue(); // 구조체에 배열 큐를 동적 메모리 할당할 변수 
int freeQueue(QueueType *cQ); // 동적 메모리 할당을 해제할 함수 
int isEmpty(QueueType *cQ); // 큐가 비었는지 확인하는 함수 
int isFull(QueueType *cQ); // 큐가 꽉차있는지 확인하는 함수 
void enQueue(QueueType *cQ, element item); // 큐에 입력받은 값을 요소로 저장하는 함수 
void deQueue(QueueType *cQ, element* item); // 큐에 요소를 제거하는 함수 
void printQ(QueueType *cQ); // 큐를 출력하는 함수 
void debugQ(QueueType *cQ); // 큐의 요소와 front, rear을 출력하는 함수 
element getElement(); // 사용자로부터 요소를 입력받는 함수 

int main(void)
{
	QueueType *cQ = createQueue(); // 선언한 구조체 *cQ에 배열 큐를 동적 메모리 할당 
	element data; // 사용자로부터 입력받은 값을 저장할 변수 
	char command; // 메뉴를 입력받을 변수 

	printf("[----- [김현민] [2018038036] -----]");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {  
		case 'i': case 'I':
			data = getElement(); // 사용자로부터 입력받은 값을 data에 저장 
			enQueue(cQ, data); // 함수내 조건에 따라 cQ에 data 저장  
			break;
		case 'd': case 'D':
			deQueue(cQ, &data); // 함수 내 조건에 따라 cQ에 값을 제거 
			break;
		case 'p': case 'P':
			printQ(cQ); // cQ 요소 출력 
			break;
		case 'b': case 'B':
			debugQ(cQ); // cQ 요소와 front, rear 출력  
			break;
		case 'q': case 'Q': 
   	        freeQueue(cQ); // 동적 메모리 할당 해제 
			break;
		default: // 위의 조건을 제외하는 메뉴를 입력받은경우 
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // 종료메뉴인 Q가 나올 때 까지 do-while 반복 

	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType)); // cQ 동적 메모리 할당 
	cQ->front = 0; // 초기화 
	cQ->rear = 0; // 초기화 
	return cQ;
}

int freeQueue(QueueType *cQ) 
{
    if(cQ == NULL) return 1; 
    free(cQ); // cQ 동적 메모리 할당 해제 
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item); // 사용자로부터 큐에 저장될 요소 저장 
	return item; // 인풋받은 요소 리턴 
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
	if( cQ -> front == cQ -> rear ) // front와 rear가 같은 경우 -> cQ가 비어있는 경우 
		return 1;
	else
		return 0;
}

/* complete the function */
int isFull(QueueType *cQ)  
{
	if( cQ -> front == (((cQ -> rear)+1) % MAX_QUEUE_SIZE)) /* front와 연산한 rear의 값이 같은경우 
	연산 : rear의 다음위치가 최대크기라면 0으로 보내고 그 값이 front와 같은 경우 -> rear가 한 바퀴를 돌아 0으로 도착 -> 원형큐 특징 */
		return 1; 
	else
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
	if(isFull(cQ) == 1) // 큐가 꽉찬지 검사 
	{
		printf("unavilable. Queue is full.\n");
	}
	else
	{
		cQ -> rear = ((cQ -> rear)+1) % MAX_QUEUE_SIZE; // rear가 다음 위치로 이동
		cQ -> queue[cQ->rear] = item; // rear가 가르키는 위치에 입력받은 데이터를 저장 / 선입선출이기에 rear사용 
	}
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{	
	if(isEmpty(cQ) == 1) // 큐가 비었는지 검사 
	{
		printf("unavilable. Queue is empty.\n");
	}
	else
	{
		cQ -> front = ((cQ -> front)+1) % MAX_QUEUE_SIZE; // front를 다음 위치로 이동 
		cQ -> queue[cQ->front] = NULL; // front가 가르키는 위치에 있는 값을 제거 / 선입선출이기에 front 사용 
	}
}


void printQ(QueueType *cQ)
{
	int i, first, last; // 출력 연산 용 변수 

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; // 연산한 front의 값을 first에 저장 
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;  // 연산한 rear의 값을 last에 저장 

	printf("Circular Queue : [");

	i = first; 
	while(i != last){ // i가 last가 아닐 때 까지 큐의 i번째 요소 출력 -> front부터 rear까지의 값 출력 
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE; // i 연산 

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{ 
	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) // i가 최대 크기 이상이 될 때 까지 반복 
	{
		if(i == cQ->front) { // i가 front와 같을 경우 
			printf("  [%d] = front\n", i); 
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); // i는 cQ의 i번째 배열 

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); 
}


