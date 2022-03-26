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

typedef struct node { // Ʈ���� ��� �� ����ü ��� 
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h); // ���ǿ� ���� head�� �ʱ�ȭ�ϰ� ��ǲ���� h�� ���� �Ҵ� �� �⺻ ���� �����ϴ� �Լ� 

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
	char command; // ����ڷ� ���� �޴��� �Է¹��� ������ ����  
	int key; // �Է¹��� Ű��  
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



void inorderTraversal(Node* ptr) // �������� �ݺ� ��� �� ��� �Ұ��� �� �� ��� �� ���������� ���  
{
	if(ptr)
	{
		inorderTraversal(ptr->left);
		printf("%d  ", ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr) // �켱 ��� �� ���� ��� �� ��� �������� ��� �Ұ��� �϶� ���������� ��� 
{
	if(ptr)
	{
		printf("%d  ", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr) // �������� ��� �� ��� �����ε� ��� �Ұ��� �� �� ��� 
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
	Node *p = (Node*)malloc(sizeof(Node)); // ���� �� ���  
	Node *n; // ����� ��� 
	p->key = key; // ���� �� ��� �ʱⰪ ����  
	p->right = NULL;
	p->left = NULL;
	
	if ( head->left == NULL ) // ��Ʈ��尡 ������� ��Ʈ���� ����  
	{
		head->left = p;
		return 0;
	}
	else
	{
		n = head->left; // n �ʱ� ��ġ ����  
		
		while( 1 ) // �������θ� ���� Ż�� 
		{
			if( p->key < n->key ) // ��ǲ���� Ű ������ ���� ��ġ ����� Ű���� �� ũ��  
			{
				if( n->left == NULL ) // n���� ���� ���� left�� ���ٸ� 
				{
					n->left = p; // n�� left��ġ�� p ���� �� ���� 
					return 0;
				}
				n = n->left; // left�� �ִٸ� n �������� �̵� 
			}
			else if( p->key > n->key ) // ��ǲ���� Ű ������ ���� ��ġ ����� Ű���� �� �۴ٸ�
			{				
				if( n->right == NULL ) // n���� ū ���� right�� ���ٸ�
				{
					n->right = p; // n�� right��ġ�� p ���� �� ���� 
					return 0;
				}
				n = n->right; // right�� �ִٸ� n ���������� �̵�
			}
			else if( p->key == n->key ) // ��ǲ���� Ű ���� ���� ��ġ ����� Ű���� ���ٸ�  
			{
				printf("unavailable. same key value is already exists."); // �����޼��� ��� �� ���� �� ��� �ʱ�ȭ �� ���� 
				free(p);
				return 0;
			}
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	Node *n; // ������ ���  
	Node *p; // ������ ����� �θ��� 
	if ( head->left == NULL ) // ��Ʈ��尡 ������ �����޼��� ��� �� ���� 
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		n = head->left; // n�� �ʱ� ��ġ ���� 
		
		while( 1 ) // Ʈ�� �� �ϴܿ��� key���� ��ã�� �� ���� 
		{
			if( n->key == key ) // ���� ���� ã�� ��� 
			{
				if( n->left == NULL && n->right == NULL) // ������ ��忡 �ڽĳ�尡 ���� ��� ��常 ���� 
				{
					free(n); 
					return 0;
				}
				else if( n->left != NULL || n->right != NULL) // ������ ��忡 �ڽĳ�尡 ���� ��� ��常 ���� 
				{
					printf("unavailable. this node is not leaf node");
					return 0;
				}
			}
			else if( key < n->key ) // key ���� ���� ��ġ ����� key���� �� ũ�ٸ�  
			{
				p = n; // p�� ���� ��ġ ���� �� n�� �������� �̵� 
				n = n->left;
			}
			else if( key > n->key ) // key ���� ���� ��ġ ����� key���� �� �۴ٸ� 
			{
				p = n; // p�� ���� ��ġ ���� �� n�� ���������� �̵�
				n = n->right;
			}
			else if( n->key != key && n->left == NULL && n->right == NULL) // ���� ��� ������ �������� ���ϴ� ��� 
			{
				printf("unavailable. there is no same value in tree"); // �����޼��� ��� �� ���� 
				return 0;
			}
		}
	}
}

Node* searchRecursive(Node* ptr, int key)
{
	if( ptr == NULL ) // ��尡 ������� ���� null 
		return NULL;
		
	else if( ptr->key == key ) // key���� ���� ��尡 ������ �ش� ��� ���� 
		return ptr;
	
	else if( key < ptr->key )  // ��ǲ�� key ������ ����� key���� ũ�� ��� �������� �̵� �� ���( �� ���� key���� ���� ��� Ž��) 
		return searchRecursive(ptr->left, key);
		
	else if( key > ptr->key ) // ��ǲ�� key ������ ����� key���� ������ ��� ���������� �̵� �� ���( �� ū key���� ���� ��� Ž��) 
		return searchRecursive(ptr->right, key);
		
}

Node* searchIterative(Node* head, int key)
{
	Node *n;
	
	if( head == NULL ) // ��尡 ������� ���� null 
		return NULL;
		
	n = head->left; // n�� �ʱ� ��ġ ���� 
		
	while( 1 )  
	{
		if( n->key == key ) // ���� ���� ã�� ��� ���� n 
			return n;
			
		else if( key < n->key ) // ��ǲ���� Ű������ n�� Ű���� �� ū ��� n�� �������� �̵� 
			n = n->left;
		
		else if( key > n->key ) // ��ǲ���� Ű������ n�� Ű���� �� ���� ��� n�� ���������� �̵� 
			n = n->right;
			
		else if( n->key != key && n->left == NULL && n->right == NULL) // ���� ��� ������ �������� ���ϴ� ��� ���� null 
			return NULL;
	}
	
}

int freeBST(Node* head)
{
	if( head != NULL ) // ��尡 null�� �ƴ� ��� 
	{
		if( head->left != NULL ) // ����� left�� null�� �ƴϸ� ��� left ���(Ž�� �� ���� �Ҵ� ����) 
			freeBST( head->left );
		if ( head != head->right ) // ����� right�� �����θ� ����Ű�� head��尡 �ƴ϶�� right ���(Ž�� �� ���� �Ҵ� ����) 
			freeBST( head->right );
		free( head ); // Ž���� ��� ���� �Ҵ� ���� 
	}
}





