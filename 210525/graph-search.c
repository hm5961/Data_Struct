/*
 * Graph Search
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10 // �־��� vertex �ִ� ��  

#define FALSE 0 // bfs�� ���� ���� 
#define TRUE 1 

short int visited[MAX_VERTEX] = {0};

typedef struct graph_node{  // �׷����� edge�� �ش��ϴ� �κ� 

	int vertex;
	struct node* link;
	
}graph_node;

typedef struct graph_data{ // �׷��� ����ü 

	graph_node* adj_list[MAX_VERTEX];
	int ver_num;
	int edg_num;
		
}graph_data;

typedef struct queue_node{ // bfs�� ���� ���� 
	struct queue_node* link;
	int vertex;
}queue_node;

queue_node* front, * rear;
void addq(int);
int deleteq();

void initialize_graph(); // �׷����� �ʱ�ȭ���ִ� �Լ� 
void insert_vertex(); // vertex�� �����ϴ� �Լ� 
int insert_edge(int num1, int num2 ); // edge�� �����ϴ� �Լ� 
void depth_first_search(int v); // ���� �켱 Ž���� �ϴ� �Լ� 
void breath_first_search(); // �ʺ� �켱 Ž���� �ϴ� �Լ� 
void print_graph(); // �׷��� ����ϴ� �Լ� 
void free_graph(); // �׷����� �����Ҵ��� �����ϴ� �Լ� 


graph_data *gr; // ���� 288p���� �Լ��� �⺻������ graph�� ���� ����ϱ淡 �������� ���� 
	
int main()
{
	char command;
	int num1, num2; // edge�� �ӽ� �����ϴ� ���� 
	
	printf("[----- [������] [2018038036] -----]");
	do{
		printf("\n");
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                         Graph Searches                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Breath First Search          = b \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize_graph();
			break;
		case 'v': case 'V':
			insert_vertex();
			break;
		case 'e': case 'E':
			printf("Insert Edge : ");
			scanf("%d %d",num1, num2);
			insert_edge(num1, num2);
			break;
		case 'd': case 'D':
			num1 = 0;
			depth_first_search( num1 ); 
			break;

		case 'b': case 'B':
			num1 = 0;
			breath_first_search( num1 );
			break;
			
		case 'p': case 'P':
			print_graph();
			break;

		case 'q': case 'Q':
			free_graph();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

void initialize_graph() {
	
	int i; // for���� �� ���� 
	gr = (graph_data*)malloc(sizeof(graph_data)); // ���� gr�� �����Ҵ� 
	gr->ver_num = 0; // gr�� �ʱ�ȭ 
	for( i=0; i<MAX_VERTEX; i++)
		gr->adj_list[i] = NULL;
}


void insert_vertex(){
	
	if ( gr->ver_num > MAX_VERTEX-1 ) // vertex�� ���� �ִ��� �����޼��� ��� 
		printf("unavailable. space of vertex if full");
	else // ver_num ��� 
		gr->ver_num++;
}

int insert_edge(int num1, int num2){
	
	graph_node *node; //���� ���� �� �߰��� ���, �̻��� �������� 
	graph_node *n, *m; //Ư�������� ��ġ �ӽ� ����� ���
	int i;
	
	if(num1 == num2) // �ڱ� ���� �� �����޼��� ��� �� ���� 
	{
		printf("error.");
		return; 
	}
	if(num1 > gr->ver_num || num2 > gr->ver_num ) // �־��� vertex������ �� ū��� �����޼��� ��� �� ���� 
	{
		printf("error"); 
		return;
	}
	 /* ������� �Էµ� vertex �ȿ��� num1 �ְ� 
	  num2�� ������ ���� ���
	  n ���� ��ġ�� NULL�� ���, �׷��� ������� �� �ٸ� ������� edge���� 
	 */
	for(i=0; i<gr->ver_num; i++)
	{
		if( i == num1)
		{	
			n = gr->adj_list[i];
			while( n->vertex == num2 ) 
			{
				/*
				if( insert_edge == 1)
				{
					printf("unavailable. %d to %d edge is already exsist",num2, num1); 
					return 1;
				} 
				else 
				{*/
				// �۵� Ȯ�� �� ��͹� �����Ϸ� ������ ���� 
					if( n->link != NULL )
					{
						while( n->link != NULL )
							n = n->link;
					}
					node = (graph_node*)malloc(sizeof(graph_node));
					n->link = node;
					node->vertex = num2;
					node->link == NULL; 
				// }
			n = n->link;
			}	
			 
		}
	}
}
void depth_first_search( v ){
	
	graph_node *w; // for������ Ž���� 
	visited[v] = TRUE;  
	printf("%5d", v);
	for( w=gr->adj_list[v]; w; w = w->link) // w�� �Ѱܰ��鼭 Ž�� 
		if(!visited[w->vertex]) // w�� vertex�� �湮���� ���� ���  
			depth_first_search(w->vertex); // ��� 
}

void breath_first_search( v ){
	
	graph_node* w; // for������ Ž���� 
	front = rear = NULL;
	printf("%5d",v);
	visited[v] = TRUE; 
	addq(v);
	while( front ) //front�� �ƴ� �� ���� v�� deleteq()�� ���� �����ϰ� 
	{
		v = deleteq();
		for ( w = gr->adj_list[v]; w; w = w->link) // w�� �Ѱܰ��� Ž�� 
			if (!visited[w->vertex]) // w�� vertex�� �湮���� ���� ��� 
			{
				printf("%5d", w->vertex); // ��� 
				addq(w->vertex); // queue�� �߰� 
				visited[w->vertex] = TRUE; // w�� vertex�� true�� 
			}
	}
}

void print_graph(){
	
	int i; // for���� �� 
	graph_node *n; // ��ġ �ӽ� ����� 
	
	for( i=0; i<gr->ver_num; i++ )
	{
		printf(" [%d]  ",i); // vertex ��� 
		n = gr->adj_list[i];
		while( n != NULL )
		{
			printf("  %d ",n->vertex);
			n = n->link;
		}
	}
	
}


void free_graph(){
	
	int i; // for ���� �� 
	graph_node *n, *m; // ��ġ �ӽ� ����� 
	
	for( i=0; i<MAX_VERTEX; i++ ) // ������� swap_num ���̽��� ���� 
	{
		n = gr->adj_list[i];
		while( n != NULL )
		{	 
			m = n;
			n = n->link;
			free(m);
		} 
		gr->adj_list[i] = NULL;
	}
}

void addq( i ){
	
}

int deleteq( ){
	
}

void initvisited(){
	
}

