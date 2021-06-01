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
// �迭ũ�� ���ȭ 
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE
// �ؽ����̺� ���ȭ


/* �ʿ信 ���� �Լ� �߰� ���� */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function���� ���� */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a���� �� hash table�� �����. */
int hashing(int *a, int **ht);

/* hash table���� key�� ã�� hash table�� index return */
int search(int *ht, int key);


int main()
{
	char command; // ����ڷκ��� �޴� ��ǲ���� ����
	int *array = NULL; // �迭�� ����� ������ ����
	int *hashtable = NULL; // �ؽ����̺�� ����� ������ ����
	int key = -1; // Ű
	int index = -1;

	srand(time(NULL));

	do{
		printf("[----- [������] [2018038036] -----]\n");
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
		scanf(" %c", &command); // ����ڷκ��� �޴� ��ǲ 

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
			printArray(array); // �������� �迭 ��� 
			quickSort(array, MAX_ARRAY_SIZE); // quicksort �Լ� ���� 
			printf("----------------------------------------------------------------\n");
			printArray(array); //quicksort�� �迭 ��� 
			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array); // ���� ���� �迭 ��� 
			hashing(array, &hashtable); // hashing �Լ� ���� 
			printArray(hashtable); // hashing�� �迭 ��� 
			break;

		case 'e': case 'E':
			printf("Your Key = "); // ����ڷκ��� ���� ��ǲ�޾Ƽ� 
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
	int *temp = NULL; // �����Ҵ� �� �迭�� ����ϱ����� �ʱ�ȭ 

	/* array�� NULL�� ��� �޸� �Ҵ� */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // �����Ҵ� 
		*a = temp;  /* �Ҵ�� �޸��� �ּҸ� ���� --> main���� �迭�� control �Ҽ� �ֵ��� ��*/
	} else
		temp = *a; // ��ǲ���� a�� �ʱ�ȭ �� ���� �ƴϸ� temp�� ���� 

	/* �������� �迭�� ������ ���� */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // MAX_ARRAY_SIZE��ŭ �ݺ� 
		temp[i] = rand() % MAX_ARRAY_SIZE; // i��° temp��  0 ~ MAX_ARRAY_SIZE -1 ������ �� ����

	return 0;
}

int freeArray(int *a)
{
	if(a != NULL) // a�� NULL�� �ƴϸ� �ʱ�ȭ
		free(a);
	return 0;
}

void printArray(int *a)
{
	if (a == NULL) { // a�� NULL�̸� �����޼��� ��� �� ���� 
		printf("nothing to print.\n");
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // MAX_ARRAY_SIZE��ŭ �����ϸ鼭 
		printf("a[%02d] ", i); // a[���ڸ� ������] ��� 
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // // MAX_ARRAY_SIZE��ŭ �����ϸ鼭
		printf("%5d ", a[i]); // 5��ŭ ���鰡�� a[]��� 
	printf("\n");
}


int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // ���� �迭 ��� 
	// ������ ���� �ּڰ��� ã�� �迭�� ������ ������ ���°��� �ݺ� 
	for (i = 0; i < MAX_ARRAY_SIZE; i++) // �ܺ� �������� ������ �� / ��ġ�� 
	{
		minindex = i;
		min = a[i];
		for(j = i+1; j < MAX_ARRAY_SIZE; j++) // ���� �������� Ž���ؼ� 
		{
			if (min > a[j]) // �� ���� ���� �ִٸ� �ӽ����� 
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i]; // �ӽ����� �� ������ ���� 
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // selection sort�� �迭 ��� 
	return 0;
}

int insertionSort(int *a)
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // ���� �迭 ��� 

	for(i = 1; i < MAX_ARRAY_SIZE; i++) // �ܺθ������� ������ �� / ��ġ�� 
	{
		t = a[i];
		j = i;
		while (a[j-1] > t && j > 0) // ���� �迭���� �� �� �迭���� �� ũ�� j�� 0���� Ŭ �� ���� ����  
		{
			a[j] = a[j-1]; // i�� 1�ΰ�츦 �����ϰ� �� �� ������ ���� �� ũ�ٸ� �� ���� 
			j--; // j�� �����鼭 while���� �ݺ� 
		}
		a[j] = t; // ������ ���� ���� �迭��ġ�� a[i]�� ���� 
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // Insertion sort�� �迭 ��� 

	return 0;
}

int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // ���� �迭 ��� 

	for(i = 0; i < MAX_ARRAY_SIZE; i++) 
	{
		for (j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j-1] > a[j]) // ���� �迭���� ���� �迭�� �� �۴ٸ� swapnum������� ��ü 
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); // bubblesort�� �迭 ��� 

	return 0;
}

int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // ���� �迭 ��� 

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) // h�� ��� 2�� ������ 0���� ���� �� ���� ���� 
	{
		for (i = 0; i < h; i++)
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h) // j�� h�� ���ذ��� MAX_ARRAY_SIZE���� Ŀ�� �� ���� ���� 
			{
				v = a[j]; // ���� �迭�� �ӽ����� 
				k = j; // ���� ���� ��ġ ���� 
				while (k > h-1 && a[k-h] > v) // k�� h-1���� �۰� a[k-h]�� v���� ���� �� ���� ���� 
				{
					a[k] = a[k-h]; // a[k]�� a[k-h]�� ���� 
					k -= h; // k���� h���� ���� 
				}
				a[k] = v; // a[k]�� v�� ���� 
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a); // shellsort�� �迭 ��� 

	return 0;
}

int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

	if (n > 1)
	{
		v = a[n-1]; // ���� �ʱⰪ ���� 
		i = -1;
		j = n - 1;

		while(1) 
		{
			while(a[++i] < v); // a[i]�� v���� �۴ٸ� i���� �ݺ� 
			while(a[--j] > v); // 

			if (i >= j) break; // i�� j���� ũ�ų� ���� �� ���� ���� �ݺ� 
			// swapnum ������� ��ü 
			t = a[i]; 
			a[i] = a[j];
			a[j] = t;
		}
		// swapnum ������� ��ü 
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i); // ��͸� ���� �ݺ��ϸ� ���� �� ������ �ٽ��� 
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

int hashCode(int key) {
   return key % MAX_HASH_TABLE_SIZE; // ��ǲ���� key���� �������� 0~MAX_HASH_TABLE_SIZE-1�� ������ ���� 
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL; // ������ ���� ���� �� �ʱ�ȭ 

	/* hash table�� NULL�� ��� �޸� �Ҵ� */
	if(*ht == NULL) { // ��ǲ���� ht�� �����ϴ� ���� NULL�̸� 
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); // �����Ҵ� 
		*ht = hashtable;  /* �Ҵ�� �޸��� �ּҸ� ���� --> main���� �迭�� control �Ҽ� �ֵ��� ��*/
	} else {
		hashtable = *ht;	/* hash table�� NULL�� �ƴѰ��, table ��Ȱ��, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++) // hashtable�迭�� �� ��Ҹ� -1�� ���� 
		hashtable[i] = -1;

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1; // �� ������ �ʱ�ȭ 
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) 
	{
		key = a[i]; // key���� a[i]���� 
		hashcode = hashCode(key); // a[i]���� ���̽��� ����� �� ���� 
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1) // ����� ��ġ�� �迭�� ���� �ʱ�ȭ�Ǿ��ִ� ���¸� 
		{
			hashtable[hashcode] = key; // key������ ���� 
		} else 	{

			index = hashcode; // index�� hashcode���� 

			while(hashtable[index] != -1) // hashtable[index]�� �ʱ�ȭ���� �ʾҴٸ� 
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; // index % MAX_HASH_TABLE_SIZE�� ������ �ϸ� ����Ż����� index ++  
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key; // ������ Ż���� index��ġ�� hashtable�迭�� key�� ���� 
		}
	}

	return 0;
}

int search(int *ht, int key)
{
	int index = hashCode(key); // key���� �������� ����� ���� index�� ���� 

	if(ht[index] == key) // ht[index]�� Ű���� ��ǲ���� key���� ������ 
		return index; // index�� ���� 

	while(ht[++index] != key) // ht[index]�� key�϶� ���� �����ݺ� �� index+1
	{
		index = index % MAX_HASH_TABLE_SIZE; // ������ �ݺ��Ǵ� ���� index����  
	}
	return index; // index���� 
}



