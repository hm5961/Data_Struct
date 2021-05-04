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
	if(ptr)
	{
		inorderTraversal(ptr->left);
		printf("%d", ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr)
	{
		printf("%d", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr)
	{
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("%d", ptr->key);
	}
}


int insert(Node* head, int key)
{
	Node *p = (Node*)malloc(sizeof(Node));
	Node *n;
	p->key = key;
	p->right = NULL;
	p->left = NULL;
	
	if ( head->left == NULL )
	{
		head->left = p;
		return 0;
	}
	else
	{
		n = head->left;
		while( 1 )
		{
			if( p->key < n->key )
			{
				if( n->left == NULL )
				{
					n->left = p;
					printf("%d",head->left->left->key);
					return 0;
				}
				n = n->left;
			}
			else if( p->key > n->key )
			{				
				if( n->right == NULL )
				{
					n->right = p;
					return 0;
				}
				n = n->right;
			}
			else if( p->key == n->key )
			{
				printf("unavailable. same key value is already exists.");
				free(p);
				return 0;
			}
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	Node *n;
	Node *p;
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
					free(n);
					return 0;
				}
				else if( n->left != NULL || n->right != NULL) // 삭제할 노드에 자식노드가 없는 경우 노드만 삭제 
				{
					printf("unavailable. this node is not leaf node");
					return 0;
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

Node* searchRecursive(Node* ptr, int key)
{
	
}

Node* searchIterative(Node* head, int key)
{

}

int freeBST(Node* head)
{
}





