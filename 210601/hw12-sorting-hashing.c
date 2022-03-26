/*
 * hw12-sorting-hashing.c
 *
 *  Created on: May 22, 2021
 *
 *  Homework 12: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
// 배열크기 상수화 
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE
// 해시테이블 상수화


/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command; // 사용자로부터 메뉴 인풋받을 변수
	int *array = NULL; // 배열로 사용할 포인터 변수
	int *hashtable = NULL; // 해시테이블로 사용할 포인터 변수
	int key = -1; // 키
	int index = -1;

	srand(time(NULL));

	do{
		printf("[----- [김현민] [2018038036] -----]\n");
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // 사용자로부터 메뉴 인풋 

		switch(command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array); // 기존상태 배열 출력 
			quickSort(array, MAX_ARRAY_SIZE); // quicksort 함수 실행 
			printf("----------------------------------------------------------------\n");
			printArray(array); //quicksort된 배열 출력 
			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array); // 기존 상태 배열 출력 
			hashing(array, &hashtable); // hashing 함수 실행 
			printArray(hashtable); // hashing된 배열 출력 
			break;

		case 'e': case 'E':
			printf("Your Key = "); // 사용자로부터 정수 인풋받아서 
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)
{
	int *temp = NULL; // 동적할당 후 배열로 사용하기위해 초기화 

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // 동적할당 
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a; // 인풋받은 a가 초기화 된 값이 아니면 temp에 저장 

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // MAX_ARRAY_SIZE만큼 반복 
		temp[i] = rand() % MAX_ARRAY_SIZE; // i번째 temp에  0 ~ MAX_ARRAY_SIZE -1 사이의 값 저장

	return 0;
}

int freeArray(int *a)
{
	if(a != NULL) // a가 NULL이 아니면 초기화
		free(a);
	return 0;
}

void printArray(int *a)
{
	if (a == NULL) { // a가 NULL이면 오류메세지 출력 후 리턴 
		printf("nothing to print.\n");
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // MAX_ARRAY_SIZE만큼 루프하면서 
		printf("a[%02d] ", i); // a[두자리 정수형] 출력 
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // // MAX_ARRAY_SIZE만큼 루프하면서
		printf("%5d ", a[i]); // 5만큼 공백가진 a[]출력 
	printf("\n");
}


int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // 기존 배열 출력 
	// 루프를 돌려 최솟값을 찾고 배열에 앞으로 가져다 놓는것을 반복 
	for (i = 0; i < MAX_ARRAY_SIZE; i++) // 외부 루프에서 저장한 값 / 위치로 
	{
		minindex = i;
		min = a[i];
		for(j = i+1; j < MAX_ARRAY_SIZE; j++) // 내부 루프에서 탐색해서 
		{
			if (min > a[j]) // 더 작은 값이 있다면 임시저장 
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i]; // 임시저장 돤 값으로 변경 
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // selection sort된 배열 출력 
	return 0;
}

int insertionSort(int *a)
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // 기존 배열 출력 

	for(i = 1; i < MAX_ARRAY_SIZE; i++) // 외부르프에서 저장한 값 / 위치로 
	{
		t = a[i];
		j = i;
		while (a[j-1] > t && j > 0) // 이전 배열보다 이 후 배열값이 더 크고 j가 0보다 클 때 까지 루프  
		{
			a[j] = a[j-1]; // i가 1인경우를 제외하고 이 전 루프의 값이 더 크다면 값 변경 
			j--; // j를 빼가면서 while루프 반복 
		}
		a[j] = t; // 루프를 통해 나온 배열위치에 a[i]값 삽입 
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // Insertion sort된 배열 출력 

	return 0;
}

int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // 기존 배열 출력 

	for(i = 0; i < MAX_ARRAY_SIZE; i++) 
	{
		for (j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j-1] > a[j]) // 이전 배열보다 이후 배열이 더 작다면 swapnum방식으로 교체 
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // bubblesort된 배열 출력 

	return 0;
}

int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // 기존 배열 출력 

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) // h를 계속 2로 나누며 0보다 작을 때 까지 루프 
	{
		for (i = 0; i < h; i++)
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h) // j에 h를 더해가며 MAX_ARRAY_SIZE보다 커질 때 까지 루프 
			{
				v = a[j]; // 기존 배열값 임시저장 
				k = j; // 현재 루프 위치 저장 
				while (k > h-1 && a[k-h] > v) // k가 h-1보다 작고 a[k-h]가 v보다 작을 때 까지 루프 
				{
					a[k] = a[k-h]; // a[k]에 a[k-h]값 저장 
					k -= h; // k에서 h빼며 루프 
				}
				a[k] = v; // a[k]에 v값 저장 
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a); // shellsort된 배열 출력 

	return 0;
}

int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

	if (n > 1)
	{
		v = a[n-1]; // 변수 초기값 설정 
		i = -1;
		j = n - 1;

		while(1) 
		{
			while(a[++i] < v); // a[i]가 v보다 작다면 i증가 반복 
			while(a[--j] > v); // 

			if (i >= j) break; // i가 j보다 크거나 같을 때 까지 루프 반복 
			// swapnum 방식으로 교체 
			t = a[i]; 
			a[i] = a[j];
			a[j] = t;
		}
		// swapnum 방식으로 교체 
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i); // 재귀를 통해 반복하며 범위 내 정렬을 다시함 
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

int hashCode(int key) {
   return key % MAX_HASH_TABLE_SIZE; // 인풋받은 key값을 기준으로 0~MAX_HASH_TABLE_SIZE-1의 값으로 리턴 
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL; // 포인터 변수 생성 후 초기화 

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) { // 인풋받은 ht가 참조하는 값이 NULL이면 
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // 동적할당 
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++) // hashtable배열의 각 요소를 -1로 저장 
		hashtable[i] = -1;

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1; // 각 변수들 초기화 
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) 
	{
		key = a[i]; // key값에 a[i]저장 
		hashcode = hashCode(key); // a[i]값을 베이스로 연산된 값 저장 
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1) // 연산된 위치의 배열의 값이 초기화되어있는 상태면 
		{
			hashtable[hashcode] = key; // key값으로 저장 
		} else 	{

			index = hashcode; // index에 hashcode저장 

			while(hashtable[index] != -1) // hashtable[index]가 초기화되지 않았다면 
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; // index % MAX_HASH_TABLE_SIZE로 연산을 하며 루프탈출까지 index ++  
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key; // 루프를 탈출한 index위치의 hashtable배열에 key값 저장 
		}
	}

	return 0;
}

int search(int *ht, int key)
{
	int index = hashCode(key); // key값을 기준으로 연산된 값을 index에 저장 

	if(ht[index] == key) // ht[index]의 키값이 인풋받은 key값과 같으면 
		return index; // index를 리턴 

	while(ht[++index] != key) // ht[index]가 key일때 까지 루프반복 후 index+1
	{
		index = index % MAX_HASH_TABLE_SIZE; // 루프가 반복되는 동안 index연산  
	}
	return index; // index리턴 
}



