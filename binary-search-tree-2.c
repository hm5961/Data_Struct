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
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
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

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224s
 */
void iterativeInorder(Node* node)
{
	int top = -1;
	Node* stack[MAX_STACK_SIZE];
	for(;;)
	{
		for(; node; node = node->left)
			push(node);
		node = pop();
		if(!node)
			break;
		printf("[%d]",node->key);
		node = node->right;
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	int front = rear = 0;
	Node queue[ MAX_QUEUE_SIZE ];
	if (!ptr)
		return;
	enQueue(ptr);
	for(;;)
	{
		ptr = deQueue();
		if(ptr)
		{
			printf("%d", ptr->key);
			if(ptr->left)
				enQueue(ptr->left);
			if(ptr->right)
				enQueue(ptr->right);
		}
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
	Node *n;                                                                             
	Node *p;
	Node *q;
	if ( head->left == NULL )
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		n = head->left;
		
		while( 1 ) // 트리 최 하단에서 key값을 못찾을 때 까지 
		{
			if( n->key == key ) // 같은 값을 찾은 경우 
			{
				if( n->left == NULL && n->right == NULL) // 삭제할 노드에 자식노드가 없는 경우 노드만 삭제 
				{
					if(p->left == n)
					{
						p->left = NULL;
					}
					else if(p->right == n)
					{
						p->right = NULL;
					}
					printf("삭제 자식없음");
					free(n);
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
					printf("삭제 왼쪽 자식");
					free(n);
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
					printf("삭제 오른쪽 자식");
					free(n); // n삭제 후 리턴 
					return 0;
				}
				else if( n->left != NULL && n->right != NULL) // 삭제할 노드 양쪽에 자식노드가 달린 경우 
				{
					if( p->left == n ) // n이 부모노드 왼쪽에 달린 경우  
					{	
						q = n; // n값 저장 
						n = n->right; // 오른쪽 자식에서 가장 작은 노드 
						while( n->left != NULL)
						{
							q = n;
							n = n->left;
						}
						if(q->left == n)
						{
							q->left = NULL;
							n->left = p->left->left;
							n->right = p->left->right;
							p->left = n;
							q = q->left;
							free(q);
							p->left = n;
							return 0;
						}
						else if(q->right == n)
						{
							q->right = NULL;
							n->left = q->left;
							q->left = NULL;
							p->left = n;
							free(q);
							return 0;
						}
					}
					else if( p->right == n ) // n이 부모노드 오른쪽에 달린 경우 
					{
						q = n; // n값 저장
						n = n->right; // 오른쪽 자식에서 가장 작은 노드
						while( n->left != NULL)  
						{
							q = n;
							n = n->left;
						}
						if(q->left == n)
						{
							q->left = NULL;
							n->left = p->right->left;
							n->right = p->right->right;
							q = p->right;
							free(q);
							p->right = n;
							return 0;
						}
						else if(q->right == n)
						{
							q->right = NULL;
							n->left = q->left;
							q->left = NULL;
							p->right = n;
							free(q);
							return 0; 
						}
					}
				}
			}
			else if( key < n->key )
			{
				p = n;
				n = n->left;
			}
			else if( key > n->key )
			{
				p = n;
				n = n->right;
			}
			else if( n->key != key && n->left == NULL && n->right == NULL)
			{
				printf("unavailable. there is no same value in tree");
				return 0;
			}
		}
	}
}


void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	Node* node = NULL; // 노드 위치 리턴 용 선언 
	if( top == -1 )
	{
		printf("unavailable. stack is empty.");
		return 0;
	}
	else
	{
		printf("stack[top] = %d\t top = %d\n",stack[top],top);
		node = stack[top]; 
		top--;
		return node;
	}
}

void push(Node* aNode)
{
	if( top == MAX_STACK_SIZE -1 )
	{
		printf("unavailable. stack is full.");
	}
	else
	{	
		top++;
		stack[top] = aNode;
	}
	printf("stack[top] = %d\t top = %d\n",stack[top],top);
}



Node* deQueue()
{
	
}

void enQueue(Node* aNode)
{
	
}



