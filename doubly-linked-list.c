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
/* �ʿ��� ������� �߰� if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* note: initialize�� ���������͸� �Ű������� ����
         singly-linked-list�� initialize�� �������� ���� �Ұ� */
int initialize(headNode** h);

/* note: freeList�� �̱������͸� �Ű������� ����
        - initialize�� �� �ٸ��� ���� �Ұ�
        - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
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
		freeList(*h);  // headnode�� null�� �ƴϸ� ���� �޸� ���� 

	*h = (headNode*)malloc(sizeof(headNode)); // temp�� ���� �޸� �Ҵ��ϰ� ���� 
	(*h)->first = NULL; // temp_first �ʱ�ȭ 
	return 1; //headnode ���� 
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
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // ���� ���� ������ ��� ���� �޸� �Ҵ� 
	node->key = key; // ��ǲ�� key����  
	listNode *n; // Node ���� �߰� �����
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
		
		while( n->rlink != NULL ) // ���� �ּҰ� ���� �� ���� n�� ���� node�� ����Ų�� 
		{
			n = n->rlink;
		}
		n->rlink = node; // ���� ������ node n�� node�� ����Ų�� 
		node->rlink = NULL; // �������̶� �����Ⱚ �ʱ�ȭ 
		node->llink = n;
		while( n->llink != NULL ) // ���� �ּҰ� ���� �� ���� n�� ���� node�� ����Ų�� 
		{
			n = n->llink;
		}
		return 0;
	}
		
	return 0;
}



/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {

	listNode *n; // Node ���� �߰� �����
	listNode *m; // Node ���� �߰� �����
	
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
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode)); // ���� ���� ������ ��� ���� �޸� �Ҵ� 
	node->key = key; // ��ǲ�� key����  
	listNode *n; // Node ���� �߰� �����
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
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {

	listNode *n; // Node ���� �߰� �����
	listNode *m; // Node ���� �߰� �����
	
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
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {

	listNode *node; // Node ���� �߰� �����
	listNode *n; // Node ���� �߰� �����
	listNode *m; // Node ���� �߰� �����
	
	if( h->first != NULL ) // headnode�� ����Ű�� ���� null�� �� �� ���� �ݺ� 
	{
		node = h->first; // Ž���� node �ʱⰪ ���� 
		m = NULL; // ����� node �ʱ�ȭ 
	
		while(node != NULL) // ���� �Լ� swap(a,b)�� �����ϰ� ��� / n�� m�� �ް� m�� node�� �ް� node�� �������� �ҷ����� m�� �������� n�� ����Ŵ 
			{
				n = m;
				m = node;
				node = node->rlink;
				m->rlink = n;
				if(n != NULL)
					n->llink = m; 
			}

			h->first = m; // headnode�� m�� ù��° ���� ���� 
			return 0;
	}
	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); // ���� ���� ������ ��� ���� �޸� �Ҵ� 
	node->key = key; // ��ǲ�� key����  
	listNode *n; // Node ���� �߰� �����
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
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

	return 1;
}

