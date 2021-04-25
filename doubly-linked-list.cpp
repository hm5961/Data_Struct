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
/* ?์?? ?ค๋?์ผ ์ถ๊? if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* ?จ์ ๋ฆฌ์ค?? */

/* note: initialize?? ?ด์ค?ฌ์ธ?ฐ๋? ๋งค๊ฐ๋ณ??๋ก ๋ฐ์
         singly-linked-list?? initialize?? ์ฐจ์ด?์ ?ดํด ? ๊ฒ */
int initialize(headNode** h);

/* note: freeList?? ?ฑ๊??ฌ์ธ?ฐ๋? ๋งค๊ฐ๋ณ??๋ก ๋ฐ์
        - initialize?? ?? ?ค๋ฅธ์ง? ?ดํด ? ๊ฒ
        - ?ด์ค?ฌ์ธ?ฐ๋? ๋งค๊ฐ๋ณ??๋ก ๋ฐ์?? ?ด์ ?? ?? ?์ ๊ฒ? */
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

	return 1;
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
 * list?? key?? ???? ?ธ๋?๋๋ฅ? ์ถ๊?
 */
int insertLast(headNode* h, int key) {

	return 0;
}



/**
 * list?? ๋ง์?๋ง? ?ธ๋ ?? 
 */
int deleteLast(headNode* h) {


	return 0;
}



/**
 * list ์ฒ์?? key?? ???? ?ธ๋?๋๋ฅ? ์ถ๊?
 */
int insertFirst(headNode* h, int key) {
	return 0;
}

/**
 * list?? ์ฒซ๋ฒ์ง? ?ธ๋ ?? 
 */
int deleteFirst(headNode* h) {

	return 0;
}



/**
 * ๋ฆฌ์ค?ธ์ ๋งํฌ๋ฅ? ???ผ๋ก ?? ๋ฐฐ์น
 */
int invertList(headNode* h) {

	return 0;
}



/* ๋ฆฌ์ค?ธ๋? ๊ฒ??ํ??, ?๋ ฅ๋ฐ์? key๋ณด๋ค ?ฐ๊ฐ?? ?์ค?? ?ธ๋ ๋ฐ๋ก ?์ ?ฝ์ */
int insertNode(headNode* h, int key) {

	return 0;
}


/**
 * list?์ key?? ???? ?ธ๋ ?? 
 */
int deleteNode(headNode* h, int key) {

	return 1;
}


