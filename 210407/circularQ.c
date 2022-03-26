/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4 // �ִ� ũ��� ���� ��� ����  

typedef char element; // �迭�� ��ҷ� �� ������ ���� ���� 
typedef struct { // ����� ��� ũ���� ť �迭�� ť ������ ���� ������ ������ ����ü�� ���� 
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue(); // ����ü�� �迭 ť�� ���� �޸� �Ҵ��� ���� 
int freeQueue(QueueType *cQ); // ���� �޸� �Ҵ��� ������ �Լ� 
int isEmpty(QueueType *cQ); // ť�� ������� Ȯ���ϴ� �Լ� 
int isFull(QueueType *cQ); // ť�� �����ִ��� Ȯ���ϴ� �Լ� 
void enQueue(QueueType *cQ, element item); // ť�� �Է¹��� ���� ��ҷ� �����ϴ� �Լ� 
void deQueue(QueueType *cQ, element* item); // ť�� ��Ҹ� �����ϴ� �Լ� 
void printQ(QueueType *cQ); // ť�� ����ϴ� �Լ� 
void debugQ(QueueType *cQ); // ť�� ��ҿ� front, rear�� ����ϴ� �Լ� 
element getElement(); // ����ڷκ��� ��Ҹ� �Է¹޴� �Լ� 

int main(void)
{
	QueueType *cQ = createQueue(); // ������ ����ü *cQ�� �迭 ť�� ���� �޸� �Ҵ� 
	element data; // ����ڷκ��� �Է¹��� ���� ������ ���� 
	char command; // �޴��� �Է¹��� ���� 

	printf("[----- [������] [2018038036] -----]");
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
			data = getElement(); // ����ڷκ��� �Է¹��� ���� data�� ���� 
			enQueue(cQ, data); // �Լ��� ���ǿ� ���� cQ�� data ����  
			break;
		case 'd': case 'D':
			deQueue(cQ, &data); // �Լ� �� ���ǿ� ���� cQ�� ���� ���� 
			break;
		case 'p': case 'P':
			printQ(cQ); // cQ ��� ��� 
			break;
		case 'b': case 'B':
			debugQ(cQ); // cQ ��ҿ� front, rear ���  
			break;
		case 'q': case 'Q': 
   	        freeQueue(cQ); // ���� �޸� �Ҵ� ���� 
			break;
		default: // ���� ������ �����ϴ� �޴��� �Է¹������ 
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // ����޴��� Q�� ���� �� ���� do-while �ݺ� 

	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType)); // cQ ���� �޸� �Ҵ� 
	cQ->front = 0; // �ʱ�ȭ 
	cQ->rear = 0; // �ʱ�ȭ 
	return cQ;
}

int freeQueue(QueueType *cQ) 
{
    if(cQ == NULL) return 1; 
    free(cQ); // cQ ���� �޸� �Ҵ� ���� 
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item); // ����ڷκ��� ť�� ����� ��� ���� 
	return item; // ��ǲ���� ��� ���� 
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
	if( cQ -> front == cQ -> rear ) // front�� rear�� ���� ��� -> cQ�� ����ִ� ��� 
		return 1;
	else
		return 0;
}

/* complete the function */
int isFull(QueueType *cQ)  
{
	if( cQ -> front == (((cQ -> rear)+1) % MAX_QUEUE_SIZE)) /* front�� ������ rear�� ���� ������� 
	���� : rear�� ������ġ�� �ִ�ũ���� 0���� ������ �� ���� front�� ���� ��� -> rear�� �� ������ ���� 0���� ���� -> ����ť Ư¡ */
		return 1; 
	else
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
	if(isFull(cQ) == 1) // ť�� ������ �˻� 
	{
		printf("unavilable. Queue is full.\n");
	}
	else
	{
		cQ -> rear = ((cQ -> rear)+1) % MAX_QUEUE_SIZE; // rear�� ���� ��ġ�� �̵�
		cQ -> queue[cQ->rear] = item; // rear�� ����Ű�� ��ġ�� �Է¹��� �����͸� ���� / ���Լ����̱⿡ rear��� 
	}
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{	
	if(isEmpty(cQ) == 1) // ť�� ������� �˻� 
	{
		printf("unavilable. Queue is empty.\n");
	}
	else
	{
		cQ -> front = ((cQ -> front)+1) % MAX_QUEUE_SIZE; // front�� ���� ��ġ�� �̵� 
		cQ -> queue[cQ->front] = NULL; // front�� ����Ű�� ��ġ�� �ִ� ���� ���� / ���Լ����̱⿡ front ��� 
	}
}


void printQ(QueueType *cQ)
{
	int i, first, last; // ��� ���� �� ���� 

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; // ������ front�� ���� first�� ���� 
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;  // ������ rear�� ���� last�� ���� 

	printf("Circular Queue : [");

	i = first; 
	while(i != last){ // i�� last�� �ƴ� �� ���� ť�� i��° ��� ��� -> front���� rear������ �� ��� 
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE; // i ���� 

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{ 
	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) // i�� �ִ� ũ�� �̻��� �� �� ���� �ݺ� 
	{
		if(i == cQ->front) { // i�� front�� ���� ��� 
			printf("  [%d] = front\n", i); 
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); // i�� cQ�� i��° �迭 

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); 
}


