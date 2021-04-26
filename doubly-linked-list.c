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
int freeList(headNode* h); // headnode기준으로 모든 node 동적 할당 해제 

int insertNode(headNode* h, int key); // 입력받은 값을 조건을 충족하는 위치에 삽입 
int insertLast(headNode* h, int key); // 입력받은 값을 마지막 위치에 삽입 
int insertFirst(headNode* h, int key); // 입력받은 값을 첫 위치에 삽입 
int deleteNode(headNode* h, int key);  // 조건을 충족하는 위치의 node 해제 
int deleteLast(headNode* h); // 마지막 위치의 node 해제 
int deleteFirst(headNode* h); // 첫 위치의 node 해제 
int invertList(headNode* h); // list 역순 정렬 

void printList(headNode* h); // list 순차 출력 


int main()
{
	char command; // 사용자로부터 메뉴를 입력받을 변수 선언 
	int key; // key값 입력받을 변수 
	headNode* headnode=NULL; // 함수로 넘겨줄 headnode 선언 후 초기화  

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

		switch(command) { // 입력받은 문자열을 통해 조건에 맞는 함수 사용 
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

	}while(command != 'q' && command != 'Q'); // q를 받을 때 까지 반복 

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
	
	listNode* p = h->first; // 연산용 headNode값 저장 
	listNode* prev = NULL; // 연산을 위해 초기화 
	
	while(p != NULL) { //p가 NULL이 될 때 까지 p로 다음 노드 저장, prev로 임시저장 후 동적 메모리 할당 해제한다.  
		prev = p; 
		p = p->rlink; 
		free(prev); 
	}
	free(h); // headnode를 동적 메모리 할당 해제 
	
	return 0;
}


void printList(headNode* h) {
	int i = 0; // 배열 기준 번호 측정용 
	listNode* p; // 연산용 노드 

	printf("\n---PRINT\n");

	if(h == NULL) { // headnode가 NULL이면 리턴 
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; // 연산용 노드 초기화 

	while(p != NULL) { // p가 null이 될 때 까지 p값 출력 후 다음 node 지정 반복 
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
	node->rlink = NULL; // 새 노드 link 초기화 
	node->llink = NULL;
	
	if(h->first == NULL) // headnode가 비어있을 경우 node를 가르키게 함  
	{
		insertFirst(h, key);
		free(node);
		return 0;
	}
		
	else if(h->first->rlink == NULL) // headnode 다음 노드가 없을 경우 아래 연산 오류를 막기위한 조건 
	{
		h->first->rlink = node; // 두 번째 노드가 node가 되게 하고 llink가 headnode를 가르키게 함  
		node->llink = h->first;
		return 0;
	}
		
	else 
	{
		n = h->first; // 연산용 노드 초기화 
		
		while( n->rlink != NULL ) // 다음 주소가 없을 때 까지 n이 다음 node를 가르킨다 
		{
			n = n->rlink;
		}
		n->rlink = node; // 기존 마지막 node n이 node를 가르킨다 
		node->rlink = NULL; // 마지막이라 쓰레기값 초기화 
		node->llink = n; // node의 llink를 이전 노드를 가르키게 한 
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
	
	if (h->first == NULL) // first가 가르키는 값이 없을경우 리턴0 
	{
		printf("nothing to delete\n");
		return 0;
	}
	else if(h->first->rlink == NULL) // first가 가르키는 값의 다음 값이 null인경우 아래 연산이 불가하기에 조건문 삽입 
	{
		h->first = NULL; // first가 가르키는 값 초기화 
		return 0;
	}
	
	// 그 외의 경우 
	n = h->first->rlink;  // first가 가르키는 값의 다음 값 
	m = h->first; // first가 가르키는 값 
	
	while( n->rlink != NULL ) // last를 위한 루프 
	{
		n = n->rlink;
		m = m->rlink;
	}
	
	n->llink = NULL; 
	m->rlink = NULL;
	
	free(n); // n의 링크 제거 후 초기화 
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
		return 0;
	}

	else // link를 하나 씩 밀어 node의 공간을 만든다 
	{
		node->rlink = h->first; // node가 가르키는 위치가 기존 first가 가르키는 위치와 같게한다.
		node->rlink->llink = node; // node의 다음 링크의 llink가 자신을 가르키게 한다. 
		h->first = node; //first에 자신 저장 
	}
	
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	
	if (h->first == NULL) // first가 가르키는 값이 없을경우 리턴0 
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
	
	h->first = n; // 기존값에 rlink를 가르키게하고 
	n->llink = NULL; // llink 초기화 
	
	free(m); // m 해제 

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
	
		while(node != NULL) // 기초 함수 swap(a,b)와 유사하게 사용 
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
	
	if(h->first == NULL) // first가 가르키는 값이 없을경우 리턴0 
	{
		insertFirst(h, key);
		free(node);
		return 0;
	}

	else
	{
		n = h->first; // 루프를 위한 초기화 
		
		while( n != NULL && n->key >= node->key ) // n이 null을 가르키거나 자신의 key보다 큰 값이 나올 때 까지 루프 
		{
			n = n->rlink;
		} 
		if( n == NULL )
		{
			insertLast(h, key); // key의 조건을 만족하지 못하고 끝까지 간 값이기에 last로 삽입 
			free(node);
		}
		else // 그 외의 경우 insertFirst와 node위치만 다르고 유사 
		{
			node->rlink = n;  
			node->llink = node->llink;
			n->rlink->llink = node;
			n->llink->rlink = node;
		}
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

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
	
		
	n = h->first; // 루프 연산용 node위치 지정 
	m = h->first->rlink;
	while( n->rlink != NULL && n->key != key ) // key와 같은 값이 존재하거나 null이되어 루프 탈출 
	{
		n = n->rlink;
	}
	if( n->rlink != NULL || n->key != key ) // 두 조건을 모두 만족하는 경우는 deleteLast와 같다. 
	{
		deleteLast(h);
		return 0;
	}
	else if ( n->rlink == NULL) // 두 경우를 모두 만족하지 못한 경우는 리스트 해제하지 않는다. 
	{
		printf("There is no equal value\n");
		return 0;
	}
	else // node->key와 같은 값이 있는경우 deleteFirst와 다른 위치의 node에서 유사한 연산 
	{
		m = n->llink;
		m->rlink = n->rlink;
		n->rlink->llink = m;
		
		free(n);
	}
	
	return 0;
}

