/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode; // 이중연결원형리스트로 사용 할 구조체 선언 

/* 함수 리스트 */
int initialize(listNode** h); // 구조체 h를 이중연결원형리스트로 사용하기 위해 동적 할당 
int freeList(listNode* h); //프로그램 종료 전 동적 할당 해제 
int insertLast(listNode* h, int key); // 입력받은 key값을 가진 node를 리스트의 마지막 위치에 해당하는(h->llist)에 삽입한다. 
int deleteLast(listNode* h); // 리스트의 마지막 위치에 해당하는(h->llist)에 있는 노드를 삭제한다.
int insertFirst(listNode* h, int key); // 입력받은 key값을 가진 node를 리스트의 처음 위치에 해당하는(h->rlist)에 삽입한다. 
int deleteFirst(listNode* h); // 리스트의 처음 위치에 해당하는(h->rlist)에 있는 노드를 삭제한다.
int invertList(listNode* h); // 리스트를 역순으로 뒤집는다. 

int insertNode(listNode* h, int key); 
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command; // 사용자로부터 메뉴를 입력받을 션수 선언 
	int key; // key값 입력받을 변수 
	listNode* headnode=NULL; // 함수로 넘겨줄 headnode 선언 후 초기화  

	printf("[----- [김현민] [2018038036] -----]");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) { // 입력받을 문자를 통해 조건에 맞는 함수 사용 
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

	}while(command != 'q' && command != 'Q'); //q를 받을 때 까지 루프 반복 

	return 1;
}


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999; 
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h){

	listNode* n = h->rlink; // 순차적으로 넘어갈 연산용 노드 
	listNode* m = NULL; // 노드 초기화 전 중간 저장용 노드 
	
	while(n != h) // while이 h가 될 때 까지 n으로 다음 노드를 검색하며, m으로 임시 저장 후 할당 해제 
	{
		m = n; 
		n = n->rlink;
		free(m);
	}
	free(h); // 헤드노드도 동적 할당 해제 
	
	return 0;
}



void printList(listNode* h) {
	int i = 0; // 노드 수 카운트용 변수 
	listNode* p; 

	printf("\n---PRINT\n");

	if(h == NULL) { // h가 동적할당 후 초기화 되지 않았으면 아래 출력 
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink; // 순차적으로 넘어갈 연산용 노드 

	while(p != NULL && p != h) { // p가 NULL이면서 h일 때 까지 반복 
		printf("[ [%d]=%d ] ", i, p->key); // h로 부터의 순서와 그 때의 key값 출력 
		p = p->rlink; // p는 다음 노드 탐색 
		i++; // 카운트 +1 
	}
	printf("  items = %d\n", i); // 헤드노드를 제외한 노드 수 출력 


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); // 헤드노드의 정보 출력 

	i = 0; // i 초기화 
	p = h->rlink; // p 초기화 
	while(p != NULL && p != h) { // p가 NULL이면서 h일 때 까지 반복 
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); // h부터 순차적으로 i번째인 노드의 key값과 노드의 llink, rlink, 주소값 출력   
		p = p->rlink; // 다음 노드로 순차 이동 
		i++; // 카운트 +1 
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 삽입할 새로운 노드 동적 할당 
	node->key = key; // 인풋받은 key를 node에 저장 
	listNode* n; // 중간 연산으로 위치를 저장할 노드 
	
	n = h->llink; // 초기 위치 지정 -> 원형 리스트의 마지막에 해당하는 부분 
	
	// 마지막에 해당하는 n과 h사이에 node를 삽입 하기 위해 n-node-h 순서로 링크 정리 
	node->rlink = h; 
	n->rlink = node;
	node->llink = n;
	h->llink = node;
	return 0;

}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) {

	listNode* n; // 삭제할 대상이 될 노드 
	
	if( h->rlink == h ) // 리스트에 헤드노드 밖에 없다면 연산하지 않고 리턴 0 
	{
		printf("unavailable. node is empty\n");
		return 0;
	}
	else // 그 외의 경우는 연산 
	{
		n = h->llink; // 초기 위치 지정 -> 원형 노드의 마지막에 해당하는 부분 
		
		// 마지막에 해당하는 n을 삭제하기 위해 n->llink와 h의 링크들을 직접 연결 
		n->llink->rlink = h;
		h->llink = n->llink;
		free(n); // n 동적 할당 해제 
		return 0;
	}
	
}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 삽입할 새로운 노드 동적 할당 
	node->key = key; // 인풋받은 key를 node에 저장 
	listNode* n; // 중간 연산으로 위치를 저장할 노드 

	n = h->rlink; // 초기 위치 지정 ->  원형 리스트의 처음에 해당하는 부분 
	
	// 처음에 해당하는 n과 h사이에 node를 넣기위해 h-node-n순으로 링크 정리 
	node->rlink = n;
	h->rlink = node;
	n->llink = node;
	node->llink = h;
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) {

	listNode* n; // 삭제할 대상이 될 노드 
	
	if( h->rlink == h ) // 리스트에 헤드노드 밖에 없다면 연산하지 않고 리턴 0  
	{
		printf("unavailable. node is empty\n");
		return 0;
	}
	
	else
	{
		n = h->rlink; // 초기 위치 지정 ->  원형 리스트의 처음에 해당하는 부분 
		// 처음에 해당하는 n을 삭제하기 위해 n->rlink와 h의 링크들을 직접 연결 
		h->rlink = n->rlink;
		n->rlink->llink = h;
		free(n);
		return 0;
	}
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) {

	listNode *node; // 탐색용 노드 
	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	
	if( h->rlink != h )
	{
		node = h; // 탐색용 node 초기 위치 지정 
		m = NULL; // 연산용 node 초기화 
	
		while(node != NULL )
			{
				n = m;
				m = node;
				node = node->rlink;
				m->rlink = n;
				if(n != NULL)
					n->llink = m; 
			}

			h = m;
			return 0;
	}
}



/**
 *  리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 
 **/
int insertNode(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	listNode* n;
	
	if( h->rlink == h ) // 리스트에 헤드노드 밖에 없다면 
	{
		printf("There is no equal value\n");
		free(node);
		return 0;
	}
	
	
	node = h->rlink;
	node->key = key;
	n = h->rlink;
		
	while( n->rlink != h || n->key <= node->key )
	{
		n = n->rlink;
	}
	if( n->key > node->key )
	{	
		node->rlink = n;
		n->llink->rlink = node;
		node->llink = n->llink;
		n->llink = node;
		return 0;
	}		
	else if( n->rlink == h )
	{
		printf("There is no equal value\n");
		free(node);
		return 0;
	}
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) {

	
	listNode* n;
	n = h->rlink;
	n->key = key;
	
	if( h->rlink->llink == h )
	{
		printf("unavailable. node is empty\n");
		return 0;
	}
	else
	{
		
		while( n->rlink != h || n->key != key )
		{
			n = n->rlink;
		}
		if( n->key == key )
		{	
			n->llink->rlink = n->rlink;
			n->rlink->llink = n->llink;
			free(n);
			
			return 0;
		}		
		else if( n->rlink == h )
		{
			printf("There is no equal value\n");
			return 0;
		}
	}
}


