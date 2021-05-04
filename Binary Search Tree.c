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

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

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
	char command;
	int key;
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



void inorderTraversal(Node* ptr)
{
	
}

void preorderTraversal(Node* ptr)
{

}

void postorderTraversal(Node* ptr)
{

}


int insert(Node* head, int key)
{
	Node *p = (Node*)malloc(sizeof(Node));
	Node *n = head->left;
	p->key = key;
	
	if ( n == NULL)
	{
		p = head->left;
		return 0;
	}
	else
	{
		if( p->key == n->key )
		{
			printf("unavailable. same key value is already exists.");
			return 0;
		}
		while( 1 ) //(n->left == NULL && n->right == NULL) || (n->left == NULL && n->right == NULL) ) 
		{
			if( p->key < n->key )
			{
				if( n->left == NULL )
				{
					p = n->left;
					return 0;
				}
				n = n->left;
			}
			else if( p->key > n->key )
			{				
				if( n->right == NULL )
				{
					p = n->right;
					return 0;
				}
				n = n->right;
			}
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	Node *n = head->left;
	Node *p;
	Node *q;
	
	if ( n == NULL)
	{
		printf("unavailable. tree is empty.");
		return 0;
	}
	else
	{
		while(1)
		{
			if( n->key == key )
			{
				if( n->left == NULL && n->right == NULL)
				{
					free(n);
					return 0;
				}
				else if( n->left != NULL && n->right == NULL )
				{
					if( p->left == n )
					{
						p->left = n->left;
					}
					else( p->right == n )
					{
						p->right = n->left;
					}
					free(n);
					return 0;
				}
				else if( n->left == NULL && n->right != NULL )
				{
					if( p->left == n )
					{
						p->left = n->right;
					}
					else( p->right == n )
					{
						p->right = n->right;
					}
					free(n);
					return 0;
				}
				else if( n->left != NULL && n->right != NULL)
				{
					if( p->left == n ) 
					{	
						q = n;
						n = n->right;
						while( n->left == NULL) // 오른쪽 자식에서 가장 작은 노드 
						{
							q = n;
							n = n->left;
						}
						q->left = NULL;
						n->left = p->left->left;
						n->right = p->left->right;
						p->left = n;
					}
					else( p->right == n )
					{
						q = n;
						n = n->right;
						while( n->left == NULL) // 오른쪽 자식에서 가장 작은 노드 
						{
							q = n;
							n = n->left;
						}
						q->left = NULL;
						n->left = p->left->left;
						n->right = p->left->right;
						p->right = n;
					}
					
				}
			}
			else if( p->key < n->key )
			{
				p = n;
				n = n->left;
			}
			else if( p->key > n->key )
			{
				p = n;
				n = n->right;
			}
		}
		printf("unavailable. there is no same value in tree");
		return 0;
	}
}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}

int freeBST(Node* head)
{

}





