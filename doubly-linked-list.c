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
int freeList(headNode* h); // headnode�������� ��� node ���� �Ҵ� ���� 

int insertNode(headNode* h, int key); // �Է¹��� ���� ������ �����ϴ� ��ġ�� ���� 
int insertLast(headNode* h, int key); // �Է¹��� ���� ������ ��ġ�� ���� 
int insertFirst(headNode* h, int key); // �Է¹��� ���� ù ��ġ�� ���� 
int deleteNode(headNode* h, int key);  // ������ �����ϴ� ��ġ�� node ���� 
int deleteLast(headNode* h); // ������ ��ġ�� node ���� 
int deleteFirst(headNode* h); // ù ��ġ�� node ���� 
int invertList(headNode* h); // list ���� ���� 

void printList(headNode* h); // list ���� ��� 


int main()
{
	char command; // ����ڷκ��� �޴��� �Է¹��� ���� ���� 
	int key; // key�� �Է¹��� ���� 
	headNode* headnode=NULL; // �Լ��� �Ѱ��� headnode ���� �� �ʱ�ȭ  

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

		switch(command) { // �Է¹��� ���ڿ��� ���� ���ǿ� �´� �Լ� ��� 
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

	}while(command != 'q' && command != 'Q'); // q�� ���� �� ���� �ݺ� 

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
	
	listNode* p = h->first; // ����� headNode�� ���� 
	listNode* prev = NULL; // ������ ���� �ʱ�ȭ 
	
	while(p != NULL) { //p�� NULL�� �� �� ���� p�� ���� ��� ����, prev�� �ӽ����� �� ���� �޸� �Ҵ� �����Ѵ�.  
		prev = p; 
		p = p->rlink; 
		free(prev); 
	}
	free(h); // headnode�� ���� �޸� �Ҵ� ���� 
	
	return 0;
}


void printList(headNode* h) {
	int i = 0; // �迭 ���� ��ȣ ������ 
	listNode* p; // ����� ��� 

	printf("\n---PRINT\n");

	if(h == NULL) { // headnode�� NULL�̸� ���� 
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; // ����� ��� �ʱ�ȭ 

	while(p != NULL) { // p�� null�� �� �� ���� p�� ��� �� ���� node ���� �ݺ� 
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
	node->rlink = NULL; // �� ��� link �ʱ�ȭ 
	node->llink = NULL;
	
	if(h->first == NULL) // headnode�� ������� ��� node�� ����Ű�� ��  
	{
		insertFirst(h, key);
		free(node);
		return 0;
	}
		
	else if(h->first->rlink == NULL) // headnode ���� ��尡 ���� ��� �Ʒ� ���� ������ �������� ���� 
	{
		h->first->rlink = node; // �� ��° ��尡 node�� �ǰ� �ϰ� llink�� headnode�� ����Ű�� ��  
		node->llink = h->first;
		return 0;
	}
		
	else 
	{
		n = h->first; // ����� ��� �ʱ�ȭ 
		
		while( n->rlink != NULL ) // ���� �ּҰ� ���� �� ���� n�� ���� node�� ����Ų�� 
		{
			n = n->rlink;
		}
		n->rlink = node; // ���� ������ node n�� node�� ����Ų�� 
		node->rlink = NULL; // �������̶� �����Ⱚ �ʱ�ȭ 
		node->llink = n; // node�� llink�� ���� ��带 ����Ű�� �� 
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
	
	if (h->first == NULL) // first�� ����Ű�� ���� ������� ����0 
	{
		printf("nothing to delete\n");
		return 0;
	}
	else if(h->first->rlink == NULL) // first�� ����Ű�� ���� ���� ���� null�ΰ�� �Ʒ� ������ �Ұ��ϱ⿡ ���ǹ� ���� 
	{
		h->first = NULL; // first�� ����Ű�� �� �ʱ�ȭ 
		return 0;
	}
	
	// �� ���� ��� 
	n = h->first->rlink;  // first�� ����Ű�� ���� ���� �� 
	m = h->first; // first�� ����Ű�� �� 
	
	while( n->rlink != NULL ) // last�� ���� ���� 
	{
		n = n->rlink;
		m = m->rlink;
	}
	
	n->llink = NULL; 
	m->rlink = NULL;
	
	free(n); // n�� ��ũ ���� �� �ʱ�ȭ 
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
		return 0;
	}

	else // link�� �ϳ� �� �о� node�� ������ ����� 
	{
		node->rlink = h->first; // node�� ����Ű�� ��ġ�� ���� first�� ����Ű�� ��ġ�� �����Ѵ�.
		node->rlink->llink = node; // node�� ���� ��ũ�� llink�� �ڽ��� ����Ű�� �Ѵ�. 
		h->first = node; //first�� �ڽ� ���� 
	}
	
	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {

	listNode *n; // Node ���� �߰� �����
	listNode *m; // Node ���� �߰� �����
	
	if (h->first == NULL) // first�� ����Ű�� ���� ������� ����0 
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
	
	h->first = n; // �������� rlink�� ����Ű���ϰ� 
	n->llink = NULL; // llink �ʱ�ȭ 
	
	free(m); // m ���� 

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
	
		while(node != NULL) // ���� �Լ� swap(a,b)�� �����ϰ� ��� 
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
	
	if(h->first == NULL) // first�� ����Ű�� ���� ������� ����0 
	{
		insertFirst(h, key);
		free(node);
		return 0;
	}

	else
	{
		n = h->first; // ������ ���� �ʱ�ȭ 
		
		while( n != NULL && n->key >= node->key ) // n�� null�� ����Ű�ų� �ڽ��� key���� ū ���� ���� �� ���� ���� 
		{
			n = n->rlink;
		} 
		if( n == NULL )
		{
			insertLast(h, key); // key�� ������ �������� ���ϰ� ������ �� ���̱⿡ last�� ���� 
			free(node);
		}
		else // �� ���� ��� insertFirst�� node��ġ�� �ٸ��� ���� 
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
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

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
	
		
	n = h->first; // ���� ����� node��ġ ���� 
	m = h->first->rlink;
	while( n->rlink != NULL && n->key != key ) // key�� ���� ���� �����ϰų� null�̵Ǿ� ���� Ż�� 
	{
		n = n->rlink;
	}
	if( n->rlink != NULL || n->key != key ) // �� ������ ��� �����ϴ� ���� deleteLast�� ����. 
	{
		deleteLast(h);
		return 0;
	}
	else if ( n->rlink == NULL) // �� ��츦 ��� �������� ���� ���� ����Ʈ �������� �ʴ´�. 
	{
		printf("There is no equal value\n");
		return 0;
	}
	else // node->key�� ���� ���� �ִ°�� deleteFirst�� �ٸ� ��ġ�� node���� ������ ���� 
	{
		m = n->llink;
		m->rlink = n->rlink;
		n->rlink->llink = m;
		
		free(n);
	}
	
	return 0;
}

