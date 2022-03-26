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
#define MAX_STACK_SIZE		20 // ���� �ִ� ũ�� ���� 
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20 // ť �ִ� ũ�� ���� 
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

	
	if(*h != NULL) // ��尡 NULL�� �ƴ�  �� freeBST 
		freeBST(*h);

	*h = (Node*)malloc(sizeof(Node)); // ��带 Node*������ ���� �޸� �Ҵ� 
	(*h)->left = NULL; // ��Ʈ��尡 ���� �� ��ġ �ʱ�ȭ 
	(*h)->right = *h; // ����� ������ ������ ��� 
	(*h)->key = -9999; // ����� Ű�� ���� ���� 

	top = -1; // top, rear , front �ʱ�ȭ 

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) { // ptr�� �ڽĳ��� ��͵� ���� ����� ���� �� �� 
		recursiveInorder(ptr->left); // ���� �ڽĳ�� ��ͷ� Ž��  
		printf(" [%d] ", ptr->key); // Ž���� �� ��� 
		recursiveInorder(ptr->right); // ������ �ڽ� ��� ��ͷ� Ž�� 
	}
}

/**
 * textbook: p 224s
 */
void iterativeInorder(Node* node)
{
	int top = -1; // top �ʱ�ȭ 
	Node* stack[MAX_STACK_SIZE]; // stack ����  
	for(;;)
	{
		for(; node; node = node->left) // node�� �� ���� ���� �ڽı��� Ǫ�� 
			push(node); 
		node = pop(); // ��带 �� 
		
		if(!node) // ��尡 �ƴ� ��� ���� ����` 
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
	int rear = 0; // front , rear �ʱ�ȭ 
	Node* queue[ MAX_QUEUE_SIZE ]; // queue ���� 
	if (!ptr) //ptr ���°� �ƴϸ� ���� 
		return;
	enQueue(ptr); // ptr �� insert queue 
	for(;;)
	{
		ptr = deQueue(); //ptr�� deletequeue ���� 
		if(ptr)
		{
			printf(" [%d] ", ptr->key); // ��� 
			if(ptr->left) // ���� �ڽĳ�尡 ������ insert queue ���� �ڽ� ��� 
				enQueue(ptr->left);
			if(ptr->right)// ������ �ڽĳ�尡 ������ insert queue ������ �ڽ� ���
				enQueue(ptr->right);
		}
		else // ptr���� �ƴϸ� break 
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
	Node *n; // Ž�� �� ��� ����                                                                             
	Node *p; // ������ ������� �θ� ��� ���� 
	Node *q; // 2�� Ž���� �θ� ��� ���� 
	if ( head->left == NULL ) // ����� ������ ������� �޼��� ��� �� ���� 
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		n = head->left;
		
		while( 1 ) // Ʈ�� �� �ϴܿ��� key���� ��ã�� �� ���� / �������� ���� 
		{
			if( n->key == key ) // ���� ���� ã�� ��� 
			{
				if( n->left == NULL && n->right == NULL) // ������ ��忡 �ڽĳ�尡 ���� ��� ��常 ���� 
				{
					if(p->left == n) // n�� ���ʿ� �޸� ��� 
					{
						p->left = NULL;  
					}
					else if(p->right == n) // n�� �����ʿ� �޸� ���  
					{
						p->right = NULL;
					}
					free(n); // n�� ��ġ �� n�� ����Ű�� ���� n���� �� ����
					return 0;
				}
				else if( n->left != NULL && n->right == NULL) // ������ ��� ���ʿ��� �ڽĳ�尡 �ִ� ��� 
				{
					if( p->left == n ) // n�� �θ��� ���ʿ� �޸� ��� 
					{
						p->left = n->left; // n�� �ڽĳ�带 p�� �ڽĳ��� 
					}
					else if( p->right == n ) // n�� �θ��� �����ʿ� �޸� ��� 
					{
						p->right = n->left; // n�� �ڽĳ�带 p�� �ڽĳ���
					}
					free(n); //
					return 0;
				}
				else if( n->left == NULL && n->right != NULL ) // ������ ��� �����ʿ��� �ڽĳ�尡 �ִ� ���
				{
					if( p->left == n ) // n�� �θ��� ���ʿ� �޸� ���
					{
						p->left = n->right; // n�� �ڽĳ�带 p�� �ڽĳ���
					}
					else if( p->right == n ) // n�� �θ��� �����ʿ� �޸� ��� 
					{
						p->right = n->right; // n�� �ڽĳ�带 p�� �ڽĳ���
					}
					free(n); // n���� �� ���� 
					return 0;
				}
				else if( n->left != NULL && n->right != NULL) // ������ ��� ���ʿ� �ڽĳ�尡 �޸� ��� 
				{
					if( p->left == n ) // n�� �θ��� ���ʿ� �޸� ���  
					{	
						q = n; // n�� ���� 
						n = n->right; // n�� ������ �ڽĿ��� ���� ���� ����, q�� �� ����� �θ�� ���� 
						while( n->left != NULL)
						{
							q = n;
							n = n->left;
						}
						if(q->left == n) // �����ʿ��� ���� ���� ��� n�� �θ� ���ʿ� ���� �� 
						{
							q->left = NULL; // q �ʱ�ȭ �� q�� �ڽĳ�带 n�� �޴´�.
							n->left = p->left->left;
							n->right = p->left->right;
							p->left = n; 
							free(q); // q���� �� 
							p->left = n; // ���� q��ġ�� n �̵� 
							return 0; // ���� 0 
						}
						else if(q->right == n) // q�� ����Ű�� ���� n�� �ް� q��ġ�� �̵� �� q ����, ���� 
						{
							q->right = NULL; // q �ʱ�ȭ �� q�� �ڽĳ�带 n�� �޴´�.
							n->left = q->left;
							q->left = NULL;
							p->left = n; // ���� q��ġ�� n �̵� 
							free(q); // q���� �� ���� 0 
							return 0;
						}
					}
					else if( p->right == n ) // n�� �θ��� �����ʿ� �޸� ��� 
					{
						q = n; // n�� ����
						n = n->right; // n�� ������ �ڽĿ��� ���� ���� ����, q�� �� ����� �θ�� ���� 
						while( n->left != NULL)  
						{
							q = n;
							n = n->left;
						}
						if(q->left == n) // q�� ����Ű�� ���� n�� �ް� q��ġ�� �̵� �� q ����, ���� 
						{
							q->left = NULL; // q �ʱ�ȭ �� q�� �ڽĳ�带 n�� �޴´�.
							n->left = p->right->left;
							n->right = p->right->right;
							q = p->right;
							free(q); // q���� �� 
							p->right = n; // ���� q��ġ�� n �̵� 
							return 0; // ���� 0 
						}
						else if(q->right == n) // q�� ����Ű�� ���� n�� �ް� q��ġ�� �̵� �� q ����, ���� 
						{
							q->right = NULL; // q �ʱ�ȭ �� q�� �ڽĳ�带 n�� �޴´�.
							n->left = q->left;
							q->left = NULL;
							p->right = n; // ���� q��ġ�� n �̵� 
							free(q); // q���� �� ���� 0 
							return 0; 
						}
					}
				}
			}
			else if( key < n->key ) // ã�� key������ ������ġ n�� key���� �� ũ�� 
			{
				p = n; // p�� n�� �����ϰ� 
				n = n->left; // n ���� �ڽĳ��� Ž�� 
			}
			else if( key > n->key )
			{
				p = n; // p�� n�� �����ϰ� 
				n = n->right; // n ������ �ڽĳ��� Ž�� 
			}
			else if( n->key != key && n->left == NULL && n->right == NULL) // Ʈ���� ������ Ž������ �� key���� ��ġ���� ������ 
			{
				printf("unavailable. there is no same value in tree"); // �޼��� ��� �� ���� 
				return 0;
			}
		}
	}
}


void freeNode(Node* ptr) // ��ͷ� ��尡 ����Ű�� �ڽ� ��� �ʱ�ȭ �� ��� �ʱ�ȭ 
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head) 
{

	if(head->left == head) //����� ���ʳ�尡 �ڱ� �ڽ��̸� �ʱ�ȭ 
	{
		free(head);
		return 1;
	}

	Node* p = head->left; // ������ p���� �� �ʱ� ��ġ�� ����� ���� / ��Ʈ���� ����  

	freeNode(p); // ��Ʈ��� �� �ڽĳ�� ��ü �ʱ�ȭ 

	free(head); // ����� �ʱ�ȭ  
	return 1; // ���� 
}



Node* pop()
{
	Node* node = NULL; // ��� ��ġ ���� �� ���� 
	if( top == -1)
	{	
		return NULL; // top�� -1�̸� �ʱ�ȭ �� ���̹Ƿ� ���� �� 
	}
	else
	{
		node = stack[top];  // ��忡 �� ��� ���� �����ϰ� 
		top--; // top�� ���� ��  
		return node; // ��带 ���� 
	}
}

void push(Node* aNode)
{
	if( top >= MAX_STACK_SIZE -1 ) // top�� MAX_STACK_SIZE�� ������ �޼��� ��� 
	{
		return;
	}
	else // ���� stack[top]�� aNode ���� 
	{	
		top++;
		stack[top] = aNode;
	}
}



Node* deQueue()
{
	Node* node = NULL;
	if(front == rear) // front�� rear�� ���� �� queue�� �� �� 
	{
		return node; // ��� ���� 
	}
	else // �ٸ��ٸ�  
	{
		node = queue[front]; // node�� delete queue��� �� ���� �� 
		front++; // pront���� �� ���� node 
		return node;
	}
}

void enQueue(Node* aNode)
{
	if(rear == MAX_QUEUE_SIZE -1 ) // rear�� MAX_QUEUE_SIZE�� �������� �޼��� ���  
	{
		return;
	}
	else // queue[rear]�� �� ���� �� ���� rear++ 
	{
		queue[rear] = aNode;
		rear++;
	}
}



