/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20 // 스택 최대 크기 선언 
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20 // 큐 최대 크기 선언 
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */



int main()
{
	char command;
	int key;
	Node* head = NULL;

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
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
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	
	if(*h != NULL) // 헤드가 NULL이 아닐  때 freeBST 
		freeBST(*h);

	*h = (Node*)malloc(sizeof(Node)); // 헤드를 Node*형으로 동적 메모리 할당 
	(*h)->left = NULL; // 루트노드가 저장 될 위치 초기화 
	(*h)->right = *h; // 헤드노드 오른쪽 지정은 헤드 
	(*h)->key = -9999; // 헤드노드 키값 임의 지정 

	top = -1; // top, rear , front 초기화 

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) { // ptr의 자식노드로 재귀된 값이 노드의 형태 일 때 
		recursiveInorder(ptr->left); // 왼쪽 자식노드 재귀로 탐색  
		printf(" [%d] ", ptr->key); // 탐색된 값 출력 
		recursiveInorder(ptr->right); // 오른쪽 자식 노드 재귀로 탐색 
	}
}

/**
 * textbook: p 224s
 */
void iterativeInorder(Node* node)
{
	int top = -1; // top 초기화 
	Node* stack[MAX_STACK_SIZE]; // stack 선언  
	for(;;)
	{
		for(; node; node = node->left) // node일 때 가장 왼쪽 자식까지 푸쉬 
			push(node); 
		node = pop(); // 노드를 팝 
		
		if(!node) // 노드가 아닐 경우 루프 해제` 
			break;
		printf(" [%d] ",node->key);
		node = node->right;
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	int front = 0;
	int rear = 0; // front , rear 초기화 
	Node* queue[ MAX_QUEUE_SIZE ]; // queue 선언 
	if (!ptr) //ptr 형태가 아니면 리턴 
		return;
	enQueue(ptr); // ptr 을 insert queue 
	for(;;)
	{
		ptr = deQueue(); //ptr에 deletequeue 저장 
		if(ptr)
		{
			printf(" [%d] ", ptr->key); // 출력 
			if(ptr->left) // 왼쪽 자식노드가 있으면 insert queue 왼쪽 자식 노드 
				enQueue(ptr->left);
			if(ptr->right)// 오른쪽 자식노드가 있으면 insert queue 오른쪽 자식 노드
				enQueue(ptr->right);
		}
		else // ptr형이 아니면 break 
			break;
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


int deleteNode(Node* head, int key)
{
	Node *n; // 탐색 할 노드 선언                                                                             
	Node *p; // 삭제할 대상노드의 부모 노드 선언 
	Node *q; // 2차 탐색의 부모 노드 선언 
	if ( head->left == NULL ) // 헤드노드 왼쪽이 비었으면 메세지 출력 후 리턴 
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		n = head->left;
		
		while( 1 ) // 트리 최 하단에서 key값을 못찾을 때 까지 / 리턴으로 나감 
		{
			if( n->key == key ) // 같은 값을 찾은 경우 
			{
				if( n->left == NULL && n->right == NULL) // 삭제할 노드에 자식노드가 없는 경우 노드만 삭제 
				{
					if(p->left == n) // n이 왼쪽에 달린 경우 
					{
						p->left = NULL;  
					}
					else if(p->right == n) // n이 오른쪽에 달린 경우  
					{
						p->right = NULL;
					}
					free(n); // n의 위치 별 n을 가르키는 것을 n삭제 후 리턴
					return 0;
				}
				else if( n->left != NULL && n->right == NULL) // 삭제할 노드 왼쪽에만 자식노드가 있는 경우 
				{
					if( p->left == n ) // n이 부모노드 왼쪽에 달린 경우 
					{
						p->left = n->left; // n의 자식노드를 p의 자식노드로 
					}
					else if( p->right == n ) // n이 부모노드 오른쪽에 달린 경우 
					{
						p->right = n->left; // n의 자식노드를 p의 자식노드로
					}
					free(n); //
					return 0;
				}
				else if( n->left == NULL && n->right != NULL ) // 삭제할 노드 오른쪽에만 자식노드가 있는 경우
				{
					if( p->left == n ) // n이 부모노드 왼쪽에 달린 경우
					{
						p->left = n->right; // n의 자식노드를 p의 자식노드로
					}
					else if( p->right == n ) // n이 부모노드 오른쪽에 달린 경우 
					{
						p->right = n->right; // n의 자식노드를 p의 자식노드로
					}
					free(n); // n삭제 후 리턴 
					return 0;
				}
				else if( n->left != NULL && n->right != NULL) // 삭제할 노드 양쪽에 자식노드가 달린 경우 
				{
					if( p->left == n ) // n이 부모노드 왼쪽에 달린 경우  
					{	
						q = n; // n값 저장 
						n = n->right; // n을 오른쪽 자식에서 가장 작은 노드로, q를 그 노드의 부모로 변경 
						while( n->left != NULL)
						{
							q = n;
							n = n->left;
						}
						if(q->left == n) // 오른쪽에서 가장 작은 노드 n이 부모 왼쪽에 있을 때 
						{
							q->left = NULL; // q 초기화 전 q의 자식노드를 n이 받는다.
							n->left = p->left->left;
							n->right = p->left->right;
							p->left = n; 
							free(q); // q삭제 후 
							p->left = n; // 기존 q위치로 n 이동 
							return 0; // 리턴 0 
						}
						else if(q->right == n) // q가 가르키는 값을 n이 받고 q위치로 이동 후 q 삭제, 리턴 
						{
							q->right = NULL; // q 초기화 전 q의 자식노드를 n이 받는다.
							n->left = q->left;
							q->left = NULL;
							p->left = n; // 기존 q위치로 n 이동 
							free(q); // q삭제 후 리턴 0 
							return 0;
						}
					}
					else if( p->right == n ) // n이 부모노드 오른쪽에 달린 경우 
					{
						q = n; // n값 저장
						n = n->right; // n을 오른쪽 자식에서 가장 작은 노드로, q를 그 노드의 부모로 변경 
						while( n->left != NULL)  
						{
							q = n;
							n = n->left;
						}
						if(q->left == n) // q가 가르키는 값을 n이 받고 q위치로 이동 후 q 삭제, 리턴 
						{
							q->left = NULL; // q 초기화 전 q의 자식노드를 n이 받는다.
							n->left = p->right->left;
							n->right = p->right->right;
							q = p->right;
							free(q); // q삭제 후 
							p->right = n; // 기존 q위치로 n 이동 
							return 0; // 리턴 0 
						}
						else if(q->right == n) // q가 가르키는 값을 n이 받고 q위치로 이동 후 q 삭제, 리턴 
						{
							q->right = NULL; // q 초기화 전 q의 자식노드를 n이 받는다.
							n->left = q->left;
							q->left = NULL;
							p->right = n; // 기존 q위치로 n 이동 
							free(q); // q삭제 후 리턴 0 
							return 0; 
						}
					}
				}
			}
			else if( key < n->key ) // 찾는 key값보다 현재위치 n의 key값이 더 크면 
			{
				p = n; // p에 n을 저장하고 
				n = n->left; // n 왼쪽 자식노드로 탐색 
			}
			else if( key > n->key )
			{
				p = n; // p에 n을 저장하고 
				n = n->right; // n 오른쪽 자식노드로 탐색 
			}
			else if( n->key != key && n->left == NULL && n->right == NULL) // 트리를 끝까지 탐색했을 때 key값이 일치하지 않으면 
			{
				printf("unavailable. there is no same value in tree"); // 메세지 출력 후 리턴 
				return 0;
			}
		}
	}
}


void freeNode(Node* ptr) // 재귀로 노드가 가르키는 자식 노드 초기화 및 노드 초기화 
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head) 
{

	if(head->left == head) //헤드의 왼쪽노드가 자기 자신이면 초기화 
	{
		free(head);
		return 1;
	}

	Node* p = head->left; // 삭제용 p선언 후 초기 위치로 헤드노드 왼쪽 / 루트노드로 지정  

	freeNode(p); // 루트노드 및 자식노드 전체 초기화 

	free(head); // 헤드노드 초기화  
	return 1; // 리턴 
}



Node* pop()
{
	Node* node = NULL; // 노드 위치 리턴 용 선언 
	if( top == -1)
	{	
		return NULL; // top이 -1이면 초기화 된 값이므로 리턴 널 
	}
	else
	{
		node = stack[top];  // 노드에 팝 대상 값을 저장하고 
		top--; // top을 감소 후  
		return node; // 노드를 리턴 
	}
}

void push(Node* aNode)
{
	if( top >= MAX_STACK_SIZE -1 ) // top이 MAX_STACK_SIZE를 넘으면 메세지 출력 
	{
		return;
	}
	else // 다음 stack[top]에 aNode 저장 
	{	
		top++;
		stack[top] = aNode;
	}
}



Node* deQueue()
{
	Node* node = NULL;
	if(front == rear) // front와 rear가 같을 때 queue가 꽉 참 
	{
		return node; // 노드 리턴 
	}
	else // 다르다면  
	{
		node = queue[front]; // node에 delete queue대상 값 저장 후 
		front++; // pront증가 후 리턴 node 
		return node;
	}
}

void enQueue(Node* aNode)
{
	if(rear == MAX_QUEUE_SIZE -1 ) // rear가 MAX_QUEUE_SIZE와 같아지면 메세지 출력  
	{
		return;
	}
	else // queue[rear]에 값 저장 후 다음 rear++ 
	{
		queue[rear] = aNode;
		rear++;
	}
}



