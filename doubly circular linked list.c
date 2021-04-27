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
/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* �Լ� ����Ʈ */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;

	printf("[----- [������] [2018038036] -----]");
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


int initialize(listNode** h) {

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(*h != NULL)
		freeList(*h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* �޸� ���� */
int freeList(listNode* h){

	return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* n;

	if( h == NULL )
	{
		h = node;
		free(node);
		return 0;
	}
	else
	{
		n = h->llink;
		
		node->rlink = h;
		n->rlink = node;
		node->llink = n;
		h->llink = node;
		return 0;
	}
	
	return 1;
}


/**
 * list�� ������ ��� ����
 */
int deleteLast(listNode* h) {

	listNode* n;
	
	if( h == NULL )
	{
		printf("unavailable. node is empty");
		return 0;
	}
	else
	{
		n = h->llink;
		
		n->llink->rlink = h;
		h->llink = n->llink;
		free(n);
		/*
		n->llink = h->llink;
		h->llink = n;
		free(n->llink);
		return 0;
		*/
	}
	
	return 1;
}


/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* n;

	if( h == NULL )
	{
		h = node;
		free(node);
		return 0;
	}
	else
	{
		n = h->rlink;
		
		node->rlink = n;
		h->rlink = node;
		n->llink = node;
		node->llink = h;
		return 0;
	}

	return 1;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(listNode* h) {

	listNode* n;
	
	if( h == NULL )
	{
		printf("unavailable. node is empty");
		return 0;
	}
	else
	{
		n = h->rlink;
		
		h->rlink = n->rlink;
		n->rlink->llink = h;
		free(n);
		return 0;
	}

	return 1;

}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(listNode* h) {

	listNode *node; // Node ���� �߰� �����
	listNode *n; // Node ���� �߰� �����
	listNode *m; // Node ���� �߰� �����
	
	if( h->rlink != NULL )
	{
		node = h; // Ž���� node �ʱⰪ ���� 
		m = NULL; // ����� node �ʱ�ȭ 
	
		while(node != NULL)
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
	return 0;
}



/**
 *  ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� 
 **/
int insertNode(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* n;

	if( h == NULL )
	{
		printf("There is no equal value\n");
		free(node);
		return 0;
	}
	else
	{
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
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* n;

	if( h == NULL )
	{
		printf("There is no equal value\n");
		free(node);
		return 0;
	}
	else
	{
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
	listNode* n;
	
	if( h == NULL )
	{
		printf("unavailable. node is empty");
		return 0;
	}
	else
	{
		n = h->rlink;
		
		h->rlink = n->rlink;
		n->rlink->llink = h;
		free(n);
		return 0;
	}

	return 1;

	return 0;
}


