/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>


typedef struct Node { // 노드로 사용할 구조체 선언 / link가 다른 노드의 주소를 저장 
	int key;
	struct Node* link;
} listNode;

typedef struct Head { // 이중포인터 대신 구조체 내 구조체를 선언 
	struct Node* first;
}headNode;
 

headNode* initialize(headNode* h); // 구조체 headNode타입 h를 동적 메모리 할당하고 리턴 
int freeList(headNode* h); // h를 동적 메모리 할당 해제 

int insertFirst(headNode* h, int key); // key를 리스트의 first에 삽입 
int insertNode(headNode* h, int key); // key를 리스트의 중간에 삽입 
int insertLast(headNode* h, int key); // key를 리스트의 last에 삽입 

int deleteFirst(headNode* h); // 리스트의 first node 해제 
int deleteNode(headNode* h, int key); // 인풋받은 key값을 가진 node 해제 
int deleteLast(headNode* h); // 리스트의 last node 해제 
int invertList(headNode* h); // 리스트 역순 정렬 

void printList(headNode* h); // headnode가 가르키는 순서대로 출력 

int main()
{
	char command; // 사용자로부터 메뉴를 입력받을 변수 선언 
	int key; // key값 입력받을 변수 
	headNode* headnode=NULL; // 함수로 넘겨줄 headnode 선언 후 초기화  
	printf("[----- [김현민] [2018038036] -----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
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
			headnode = initialize(headnode);
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

	}while(command != 'q' && command != 'Q'); //q를 입력받을 때 까지 반복 

	return 1;
}

headNode* initialize(headNode* h) {

	if(h != NULL)
		freeList(h);  // headnode가 null이 아니면 동적 메모리 해제 

	headNode* temp = (headNode*)malloc(sizeof(headNode)); // temp를 동적 메모리 할당하고 리턴 
	temp->first = NULL; // temp_first 초기화 
	return temp; //headnode 리턴 
}

int freeList(headNode* h){
	
	listNode* p = h->first; // 연산용 headNode값 저장 
	listNode* prev = NULL; // 연산을 위해 초기화 
	
	while(p != NULL) { //p가 NULL이 될 때 까지 p로 다음 노드 저장, prev로 임시저장 후 동적 메모리 할당 해제한다.  
		prev = p; 
		p = p->link; 
		free(prev); 
	}
	free(h); // headnode를 동적 메모리 할당 해제 
	return 0;
}



int insertFirst(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 노드 동적 메모리 할당 
	node->key = key; // 인풋 받은 key값 저장 
	node->link = h->first; // headnode가 가르키는 주소(기존 node의 위치)를 node가 받고 
	h->first = node; // headnode는 node를 받아 headnode다음에 node가 오도록 한다. 

	return 0;
}

int insertNode(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 node 동적 메모리 할당 
	node -> key = key; // 인풋된 key저장  
	listNode *n;
	listNode *m; // Node 연결 중간 연산용 
	int i = 1, j;
	n = h->first; // headnode가 가르키던 주소를 받는다 
	m = h->first; // headnode가 가르키던 주소를 받는다 
	
	
	if ( h->first == NULL ) // 리스트가 NULL일경우 insertFirst함수를 통해 key를 node에 저장 
	{
		insertFirst(h, key);
		free(node);
		return 0;
	} 
	
	if ( n->link == NULL ) // head를 제외한 node가 하나 뿐일 때 insertLast를 통해 key를 node에 저장 
	{
		insertLast(h, key);
		free(node);
		return 0;
	}
	
	n = h->first;
	while( n->link != NULL ) // 다음 주소가 없을 때 까지 n이 다음 node를 가르킨다 
	{
		n = n->link;
		i++; // node의 수를 센다 
	}
	
	n = h->first; // n 초기화 
	n = n->link; // m의 다음 주소를 가르키기위해 사용 
	i = i/2; // 중간으로 입력받기 위한 연산 
	
	for ( j=0; j<i; j++) // 리스트의 중간을 가르키기 위한 루프 
	{
		m = m->link;
		n = n->link;
	}
	m->link = node; // m과 n사이에 node 삽입 
	node->link = n;
	
	return 0;
}

int insertLast(headNode* h, int key) {	

	listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로 값을 저장할 노드 동적 메모리 할당 
	node -> key = key; // 인풋된 key저장  
	listNode *n; // Node 연결 중간 연산용
	
	if ( h->first == NULL ) // 리스트가 NULL일경우 insertFirst함수를 통해 key를 headnode에 저장 
	{
		insertFirst(h,key);
		free(node);
		return 0;
	} 
	
	else
	{
		n = h->first; // headnode가 가르키던 주소를 받는다 
		
		while( n->link != NULL ) // 다음 주소가 없을 때 까지 n이 다음 node를 가르킨다 
		{
			n = n->link;
		}
		n->link = node; // 기존 마지막 node n이 node를 가르킨다 
		node->link = NULL; // 마지막이라 쓰레기값 초기화 
		return 0;
	}
}


int deleteFirst(headNode* h) {
	  
	if( h->first == NULL) // first가 가르키는 값이 없을경우 리턴0 
	{
		printf("unavailable. list is empty");
		return 0;
	}
	
	listNode *n; // Node 삭제 중간 연산용
	n = h->first; // n에 headnode가 가르키고 있는 주소 저장 
	h->first = n->link; // headnode가 원래 가르키고 있던 node의 다음 node를 가르키고 
	free(n);  // 기존에 가르키던 node 초기화 

	return 0;
}


int deleteNode(headNode* h, int key) {

	listNode *node;
	listNode *n;
	listNode *m; // Node 연결 중간 연산용
	int i = 0, j;
	node = h->first; // headnode가 가르키던 주소를 받는다 
	n = h->first; // headnode가 가르키던 주소를 받는다
	m = h->first; // headnode가 가르키던 주소를 받는다
	if (h->first == NULL){
		printf("unavailable. list is empty");
		return 0;
	}
	while( node->link != NULL) //node가 가르키는 값이 NULL이 될 때 까지 반복 
	{
		i++;
		node = node->link; 
		if ( node->key == key) // 탐색한 node key값이 인풋받은 key값과 같으면 
		{	
			m = m->link; 
			for(j=1; j<i; j++)
			{
				m = m->link;
				n = n->link;
			}
			n->link = m->link; // 탐색한 node 전 후의 node가 탐색한 node를 가르키지 않고  
			free(node); // 탐색한 node는 해제 
			return 0;
		}	
	}
	/*
	if ( node->link == NULL ) // 노드가 비었다면 리턴 
	{
		printf("unavailable. not match number.\n");
		return 0;
	}
	else if ( (node->key == key) && (node->link == NULL) ) 
	{
		deleteLast(h);
		return 0;
	}
	*/
	return 0;
}

int deleteLast(headNode* h) {

	listNode *n; // Node 삭제 중간 연산용
	listNode *m; // Node 삭제 중간 연산용
	int i=0, j;
	n = h->first; 
	m = h->first; 
	while( n->link != NULL ) // n이 가르키는 다음 node가 없을 때 
	{
		n = n->link;
		i++;
	}
	for(j=1; j<i; j++)
	{
		m = m->link;
	}
	m->link = NULL;
	
	free(n); // n을 동적 메모리 할당 해제 
	return 0;
}

/*
int invertList(headNode* h) {

	
	listNode *node;
	listNode *n;
	listNode *m; // Node 연결 중간 연산용
	listNode *fst;
	listNode *hd;
	fst = h->first->link;
	hd = h->first;
	n = h->first;
	int i = 0, j;
	
	n = h->first;
	
		while( n->link != NULL)
		{
			i++;
			n = n->link;
		}
		printf("a%d\n",i);
		hd->link = n;
		n = h->first;
		
		while()// fst->link != NULL )
		{
			m = h->first;
			n = h->first;
			printf("b%d\n",i);
			for(j=0; j<i; j++)
			{
				m = m->link;
			}
			for(j=0; j<i-1; j++)
			{
				n = n->link;
			}	
			m->link = n;
			if( n->link->link == n)
			{
				n->link = NULL;
				hd->link = m;
				printf("xx\n");
				return 0;
			}
			printf("c%d\n",i);
			i = i-1;
			printf("d%d\n",i);
		}
	return 0;
}
*/
int invertList(headNode* h) {

	listNode *node; //중간 연산용 node 
	listNode *n;
	listNode *m;

	if( h->first != NULL ) // headnode가 가르키는 값이 null이 될 때 까지 반복 
	{
		node = h->first; // 탐색용 node 초기값 지정 
		m = NULL; // 연산용 node 초기화 
		while(node != NULL) // 기초 함수 swap(a,b)와 유사하게 사용 / n이 m을 받고 m이 node를 받고 node가 다음값을 불러오고 m의 다음값이 n을 가르킴 
			{
				n = m;
				m = node;
				node = node->link;
				m->link = n; 
			}

			h->first = m; // headnode가 m을 첫번째 노드로 지정 
			return 0;
	}

	return 0;

}

void printList(headNode* h) {
	int i = 0; //연산용 노드 
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) { // headnode가 NULL이면 리턴 
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; // 연산용 node초기화 

	while(p != NULL) { // p가 null이 될 때 까지 p값 출력 후 다음 node 지정 반복 
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i); // 카운트 한 i 출력 
}
