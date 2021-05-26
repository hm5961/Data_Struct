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

#define MAX_VERTEX 10 // 주어진 vertex 최대 수  

#define FALSE 0 // bfs를 위한 삽입 
#define TRUE 1 

short int visited[MAX_VERTEX] = {0};

typedef struct graph_node{  // 그래프의 edge에 해당하는 부분 

	int vertex;
	struct node* link;
	
}graph_node;

typedef struct graph_data{ // 그래프 구조체 

	graph_node* adj_list[MAX_VERTEX];
	int ver_num;
	int edg_num;
		
}graph_data;

typedef struct queue_node{ // bfs를 위해 삽입 
	struct queue_node* link;
	int vertex;
}queue_node;

queue_node* front, * rear;
void addq(int);
int deleteq();

void initialize_graph(); // 그래프를 초기화해주는 함수 
void insert_vertex(); // vertex를 생성하는 함수 
int insert_edge(int num1, int num2 ); // edge를 삽입하는 함수 
void depth_first_search(int v); // 깊이 우선 탐색을 하는 함수 
void breath_first_search(); // 너비 우선 탐색을 하는 함수 
void print_graph(); // 그래프 출력하는 함수 
void free_graph(); // 그래프의 동적할당을 해제하는 함수 


graph_data *gr; // 교재 288p에서 함수에 기본적으로 graph를 많이 사용하길래 전역으로 선언 
	
int main()
{
	char command;
	int num1, num2; // edge를 임시 저장하는 변수 
	
	printf("[----- [김현민] [2018038036] -----]");
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
	
	int i; // for루프 용 변수 
	gr = (graph_data*)malloc(sizeof(graph_data)); // 전역 gr을 동적할당 
	gr->ver_num = 0; // gr값 초기화 
	for( i=0; i<MAX_VERTEX; i++)
		gr->adj_list[i] = NULL;
}


void insert_vertex(){
	
	if ( gr->ver_num > MAX_VERTEX-1 ) // vertex의 수가 최대라면 오류메세지 출력 
		printf("unavailable. space of vertex if full");
	else // ver_num 상승 
		gr->ver_num++;
}

int insert_edge(int num1, int num2){
	
	graph_node *node; //조건 충족 시 추가될 노드, 미사용시 프리예정 
	graph_node *n, *m; //특정상태의 위치 임시 저장용 노드
	int i;
	
	if(num1 == num2) // 자기 간선 시 오류메세지 출력 후 리턴 
	{
		printf("error.");
		return; 
	}
	if(num1 > gr->ver_num || num2 > gr->ver_num ) // 주어진 vertex값보다 더 큰경우 오류메세지 출력 후 리턴 
	{
		printf("error"); 
		return;
	}
	 /* 현재까지 입력된 vertex 안에서 num1 있고 
	  num2가 기존에 없는 경우
	  n 다음 위치가 NULL인 경우, 그렇지 않은경우 별 다른 방법으로 edge삽입 
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
				// 작동 확인 후 재귀문 수정하려 했으나 실패 
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
	
	graph_node *w; // for문으로 탐색용 
	visited[v] = TRUE;  
	printf("%5d", v);
	for( w=gr->adj_list[v]; w; w = w->link) // w를 넘겨가면서 탐색 
		if(!visited[w->vertex]) // w의 vertex가 방문되지 않은 경우  
			depth_first_search(w->vertex); // 재귀 
}

void breath_first_search( v ){
	
	graph_node* w; // for문으로 탐색용 
	front = rear = NULL;
	printf("%5d",v);
	visited[v] = TRUE; 
	addq(v);
	while( front ) //front가 아닐 때 까지 v에 deleteq()된 값을 저장하고 
	{
		v = deleteq();
		for ( w = gr->adj_list[v]; w; w = w->link) // w를 넘겨가며 탐색 
			if (!visited[w->vertex]) // w의 vertex가 방문되지 않은 경우 
			{
				printf("%5d", w->vertex); // 출력 
				addq(w->vertex); // queue에 추가 
				visited[w->vertex] = TRUE; // w의 vertex를 true로 
			}
	}
}

void print_graph(){
	
	int i; // for루프 용 
	graph_node *n; // 위치 임시 저장용 
	
	for( i=0; i<gr->ver_num; i++ )
	{
		printf(" [%d]  ",i); // vertex 출력 
		n = gr->adj_list[i];
		while( n != NULL )
		{
			printf("  %d ",n->vertex);
			n = n->link;
		}
	}
	
}


void free_graph(){
	
	int i; // for 루프 용 
	graph_node *n, *m; // 위치 임시 저장용 
	
	for( i=0; i<MAX_VERTEX; i++ ) // 통상적인 swap_num 베이스로 삭제 
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

