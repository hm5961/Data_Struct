/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 트리로 사용 할 구조체 노드 
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h); // 조건에 따라 head를 초기화하고 인풋받은 h를 동적 할당 후 기본 값을 지정하는 함수 

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command; // 사용자로 부터 메뉴를 입력받을 문자형 변수  
	int key; // 입력받을 키값  
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL) 
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr) // 왼쪽으로 반복 재귀 후 재귀 불가능 일 때 출력 후 오른쪽으로 재귀  
{
	if(ptr)
	{
		inorderTraversal(ptr->left);
		printf("%d  ", ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr) // 우선 출력 후 왼쪽 재귀 후 출력 왼쪽으로 재귀 불가능 일때 오른쪽으로 재귀 
{
	if(ptr)
	{
		printf("%d  ", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr) // 왼쪽으로 재귀 후 어느 쪽으로도 재귀 불가능 일 때 출력 
{
	if(ptr)
	{
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("%d  ", ptr->key);
	}
}


int insert(Node* head, int key)
{
	Node *p = (Node*)malloc(sizeof(Node)); // 삽입 될 노드  
	Node *n; // 연산용 노드 
	p->key = key; // 삽입 될 노드 초기값 지정  
	p->right = NULL;
	p->left = NULL;
	
	if ( head->left == NULL ) // 루트노드가 비었으면 루트노드로 삽입  
	{
		head->left = p;
		return 0;
	}
	else
	{
		n = head->left; // n 초기 위치 지정  
		
		while( 1 ) // 리턴으로만 루프 탈출 
		{
			if( p->key < n->key ) // 인풋받은 키 값보다 현재 위치 노드의 키값이 더 크면  
			{
				if( n->left == NULL ) // n보다 작은 값인 left가 없다면 
				{
					n->left = p; // n의 left위치에 p 저장 후 리턴 
					return 0;
				}
				n = n->left; // left가 있다면 n 왼쪽으로 이동 
			}
			else if( p->key > n->key ) // 인풋받은 키 값보다 현재 위치 노드의 키값이 더 작다면
			{				
				if( n->right == NULL ) // n보다 큰 값인 right가 없다면
				{
					n->right = p; // n의 right위치에 p 저장 후 리턴 
					return 0;
				}
				n = n->right; // right가 있다면 n 오른쪽으로 이동
			}
			else if( p->key == n->key ) // 인풋받은 키 값과 현재 위치 노드의 키값이 같다면  
			{
				printf("unavailable. same key value is already exists."); // 오류메세지 출력 후 삽입 할 노드 초기화 후 리턴 
				free(p);
				return 0;
			}
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	Node *n; // 삭제할 노드  
	Node *p; // 삭제할 노드의 부모노드 
	if ( head->left == NULL ) // 루트노드가 없으면 오류메세지 출력 후 리턴 
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		n = head->left; // n의 초기 위치 지정 
		
		while( 1 ) // 트리 최 하단에서 key값을 못찾을 때 까지 
		{
			if( n->key == key ) // 같은 값을 찾은 경우 
			{
				if( n->left == NULL && n->right == NULL) // 삭제할 노드에 자식노드가 없는 경우 노드만 삭제 
				{
					free(n); 
					return 0;
				}
				else if( n->left != NULL || n->right != NULL) // 삭제할 노드에 자식노드가 없는 경우 노드만 삭제 
				{
					printf("unavailable. this node is not leaf node");
					return 0;
				}
			}
			else if( key < n->key ) // key 보다 현재 위치 노드의 key값이 더 크다면  
			{
				p = n; // p에 현재 위치 저장 후 n을 왼쪽으로 이동 
				n = n->left;
			}
			else if( key > n->key ) // key 보다 현재 위치 노드의 key값이 더 작다면 
			{
				p = n; // p에 현재 위치 저장 후 n을 오른쪽으로 이동
				n = n->right;
			}
			else if( n->key != key && n->left == NULL && n->right == NULL) // 위의 모든 조건을 충족하지 못하는 경우 
			{
				printf("unavailable. there is no same value in tree"); // 오류메세지 출력 후 리턴 
				return 0;
			}
		}
	}
}

Node* searchRecursive(Node* ptr, int key)
{
	if( ptr == NULL ) // 헤드가 비었으면 리턴 null 
		return NULL;
		
	else if( ptr->key == key ) // key값을 가진 노드가 있으면 해당 노드 리턴 
		return ptr;
	
	else if( key < ptr->key )  // 인풋된 key 값보다 노드의 key값이 크면 노드 왼쪽으로 이동 후 재귀( 더 작은 key값을 가진 노드 탐색) 
		return searchRecursive(ptr->left, key);
		
	else if( key > ptr->key ) // 인풋된 key 값보다 노드의 key값이 작으면 노드 오른쪽으로 이동 후 재귀( 더 큰 key값을 가진 노드 탐색) 
		return searchRecursive(ptr->right, key);
		
}

Node* searchIterative(Node* head, int key)
{
	Node *n;
	
	if( head == NULL ) // 헤드가 비었으면 리턴 null 
		return NULL;
		
	n = head->left; // n의 초기 위치 지정 
		
	while( 1 )  
	{
		if( n->key == key ) // 같은 값을 찾은 경우 리턴 n 
			return n;
			
		else if( key < n->key ) // 인풋받은 키값보다 n의 키값이 더 큰 경우 n을 왼쪽으로 이동 
			n = n->left;
		
		else if( key > n->key ) // 인풋받은 키값보다 n의 키값이 더 작은 경우 n을 오른쪽으로 이동 
			n = n->right;
			
		else if( n->key != key && n->left == NULL && n->right == NULL) // 위의 모든 조건을 충족하지 못하는 경우 리턴 null 
			return NULL;
	}
	
}

int freeBST(Node* head)
{
	if( head != NULL ) // 헤드가 null이 아닐 경우 
	{
		if( head->left != NULL ) // 헤드의 left가 null이 아니면 헤드 left 재귀(탐색 후 동적 할당 해제) 
			freeBST( head->left );
		if ( head != head->right ) // 헤드의 right가 스스로를 가르키는 head노드가 아니라면 right 재귀(탐색 후 동적 할당 해제) 
			freeBST( head->right );
		free( head ); // 탐색한 노드 동적 할당 해제 
	}
}





