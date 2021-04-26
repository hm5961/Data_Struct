/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) {

	if(*h != NULL)
		freeList(*h);  // headnode가 null이 아니면 동적 메모리 해제 

	*h = (headNode*)malloc(sizeof(headNode)); // temp를 동적 메모리 할당하고 리턴 
	(*h)->first = NULL; // temp_first 초기화 
	return 1; //headnode 리턴 
}

int freeList(headNode* h){
	
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 노드 동적 메모리 할당 
	node->key = key; // 인풋된 key저장  
	listNode *n; // Node 연결 중간 연산용
	node->rlink = NULL;
	node->llink = NULL;
	
	if(h->first == NULL)
	{
		h->first = node;
		//insertFirst(h, key);
		//free(node);
		return 0;
	}
		
	else if(h->first->rlink == NULL)
	{
		//h->first->rlink->key = key;
		h->first->rlink = node;
		node->llink = h->first->llink;
		//insertNode(h, key);
		//free(node);
		return 0;
	}
		
	else 
	{
		n = h->first;
		
		while( n->rlink != NULL ) // 다음 주소가 없을 때 까지 n이 다음 node를 가르킨다 
		{
			n = n->rlink;
		}
		n->rlink = node; // 기존 마지막 node n이 node를 가르킨다 
		node->rlink = NULL; // 마지막이라 쓰레기값 초기화 
		node->llink = n;
		while( n->llink != NULL ) // 다음 주소가 없을 때 까지 n이 다음 node를 가르킨다 
		{
			n = n->llink;
		}
		return 0;
	}
		
	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	
	if (h->first == NULL)
	{
		printf("nothing to delete\n");
		return 0;
	}
	else if(h->first->rlink == NULL)
	{
		h->first = NULL;
		return 0;
	}
	
		
	n = h->first->rlink; 
	m = h->first; 
	
	while( n->rlink != NULL )
	{
		n = n->rlink;
		m = m->rlink;
	}
	
	n->llink = NULL;
	m->rlink = NULL;
	
	free(n);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 노드 동적 메모리 할당 
	node->key = key; // 인풋된 key저장  
	listNode *n; // Node 연결 중간 연산용
	node->rlink = NULL;
	node->llink = NULL;
	
	if(h->first == NULL)
	{
		h->first = node;
		//insertFirst(h, key);
		//free(node);
		return 0;
	}

	else
	{
		node->rlink = h->first;
		node->rlink->llink = node;
		h->first = node;
	}
	
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	
	if (h->first == NULL)
	{
		printf("nothing to delete\n");
		return 0;
	}
	
	else if(h->first->rlink == NULL)
	{
		h->first = NULL;
		return 0;
	}
	
	n = h->first->rlink; 
	m = h->first; 
	
	n->llink = NULL;
	m->rlink = NULL;
	
	h->first = n;
	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

	listNode *node; // Node 삭제 중간 연산용
	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	
	if( h->first != NULL ) // headnode가 가르키는 값이 null이 될 때 까지 반복 
	{
		node = h->first; // 탐색용 node 초기값 지정 
		m = NULL; // 연산용 node 초기화 
	
		while(node != NULL) // 기초 함수 swap(a,b)와 유사하게 사용 / n이 m을 받고 m이 node를 받고 node가 다음값을 불러오고 m의 다음값이 n을 가르킴 
			{
				n = m;
				m = node;
				node = node->rlink;
				m->rlink = n;
				if(n != NULL)
					n->llink = m; 
			}

			h->first = m; // headnode가 m을 첫번째 노드로 지정 
			return 0;
	}
	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 노드 동적 메모리 할당 
	node->key = key; // 인풋된 key저장  
	listNode *n; // Node 연결 중간 연산용
	node->rlink = NULL;
	node->llink = NULL;
	
	if(h->first == NULL)
	{
		h->first = node;
		//insertFirst(h, key);
		//free(node);
		return 0;
	}

	else
	{
		
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	return 1;
}

