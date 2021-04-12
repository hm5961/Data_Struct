/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* ?„ìš”?? ?¤ë”?Œì¼ ì¶”ê? */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* ?¨ìˆ˜ ë¦¬ìŠ¤?? */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

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

		switch(command) {
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

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNodeê°? NULL?? ?„ë‹ˆë©?, freeNodeë¥? ?¸ì¶œ?˜ì—¬ ? ë‹¹?? ë©”ëª¨ë¦? ëª¨ë‘ ?´ì œ */
	if(h != NULL)
		freeList(h);

	/* headNode?? ???? ë©”ëª¨ë¦¬ë? ? ë‹¹?˜ì—¬ ë¦¬í„´ */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h?? ?°ê²°?? listNode ë©”ëª¨ë¦? ?´ì œ
	 * headNode?? ?´ì œ?˜ì–´?? ??.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list ì²˜ìŒ?? key?? ???? ?¸ë“œ?˜ë‚˜ë¥? ì¶”ê?
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ë¦¬ìŠ¤?¸ë? ê²??‰í•˜??, ?…ë ¥ë°›ì? keyë³´ë‹¤ ?°ê°’?? ?˜ì˜¤?? ?¸ë“œ ë°”ë¡œ ?žì— ?½ìž… */
int insertNode(headNode* h, int key) {

	return 0;
}

/**
 * list?? key?? ???? ?¸ë“œ?˜ë‚˜ë¥? ì¶”ê?
 */
int insertLast(headNode* h, int key) {

	return 0;
}


/**
 * list?? ì²«ë²ˆì§? ?¸ë“œ ?? œ
 */
int deleteFirst(headNode* h) {


	return 0;
}


/**
 * list?ì„œ key?? ???? ?¸ë“œ ?? œ
 */
int deleteNode(headNode* h, int key) {

	return 0;

}

/**
 * list?? ë§ˆì?ë§? ?¸ë“œ ?? œ
 */
int deleteLast(headNode* h) {

	return 0;
}


/**
 * ë¦¬ìŠ¤?¸ì˜ ë§í¬ë¥? ??ˆœ?¼ë¡œ ?? ë°°ì¹˜
 */
int invertList(headNode* h) {

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
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

