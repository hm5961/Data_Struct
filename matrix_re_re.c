#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col); // 동적 메모리 할당을 해 이중포인터로 리턴을 줄 함수 선언.
void print_matrix(int** matrix, int row, int col); // 배열을 출력해줄 함수를 선언.
int free_matrix(int** matrix, int row, int col); // 배열을 초기화하는 함수를 선언.
int fill_data(int** matrix, int row, int col); // 배열의 값을 저장하는 함수를 선언.
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col); // 배열 a, b를 더하는 연산을 하는 함수를 선언.
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col); // 배열 a, b를 빼는 연산을 하는 함수를 선언.
int transpose_matrix(int** matrix, int** matrix_t, int row, int col); // 배열 a를 전치하는 연산을 하는 함수를 선언.
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col); // 배열 a, b를 곱하는 연산을 하는 함수를 선언.
int main()
{
    char command; //메뉴를 받을 문자 저장
    printf("[----- [김현민]  [2018038036] -----]\n");

    int row, col; //배열의 행과 열의 크기를 받을 변수
    srand(time(NULL)); //기준시간으로부터 초를 받아 랜덤을 위한 시드 생성

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); // 사용자로 부터 행, 열의 크기 입력받음
    int** matrix_a = create_matrix(row, col); // 사용자로 부터 입력받은 크기만큼 동적메모리를 할당 후 이중 포인터 변수에 저장
    int** matrix_b = create_matrix(row, col); // 사용자로 부터 입력받은 크기만큼 동적메모리를 할당 후 이중 포인터 변수에 저장
    int** matrix_a_t = create_matrix(col, row); // 사용자로 부터 입력받은 크기만큼 동적메모리를 할당 후 이중 포인터 변수에 저장
	printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;} // 정상적으로 생성되었는지 여부 확인

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command); // 사용자로부터 메뉴 입력받음
		printf("\n");
        switch(command) //입력받은 문자로 아래 루프를 돌린다
        {
        case 'z': case 'Z': // 입력 문자가 z일 경우
            printf("Matrix Initialized\n");
            printf("matrix_a\n");
            fill_data(matrix_a, row, col); //생성된 행렬의 요소에 20미만의 랜덤 값을 저장
            print_matrix(matrix_a, row, col); //무작위 값이 저장된 행렬을 출력
            printf("matrix_b\n");
            fill_data(matrix_b, row, col); //생성된 행렬의 요소에 20미만의 랜덤 값을 저장
            print_matrix(matrix_b, row, col); //무작위 값이 저장된 행렬을 출력
            break;
        case 'p': case 'P': // 입력 문자가 p일 경우
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col); // 행렬 a 출력
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col); // 행렬 b 출력
            break;
        case 'a': case 'A': // 입력 문자가 a일 경우
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col); // 행렬 a,b를 더하고 결과를 출력
            break;
        case 's': case 'S': // 입력 문자가 s일 경우
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col); // 행렬 a에서 b를 빼고 결과를 출력한다.
            break;
        case 't': case 'T': // 입력 문자가 t일 경우
            printf("Transpose matrix_a \n");
            printf("matrix_a_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row); // 행렬 a에 대한 전칠행렬을 계산해 출력한다.
            break;
        case 'm': case 'M': // 입력 문자가 m일 경우
            printf("Multiply matrix_a with transposed matrix_a \n");
            printf("matrix_a_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row); //곱연산을 하기 전 전치 행렬을 출력한다.
            printf("matrix_a * matrix_a_t\n");
            multiply_matrix(matrix_a, matrix_a_t, row, col); //곱역산을 계산해 출력한다.
        	//free_matrix(matrix_axt, row, row);
            break;
        case 'q': case 'Q': //q가 입력된 경우
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row); //행렬 a_t에 대해 동적으로 할당한 메모리를 해제한다.
            free_matrix(matrix_a, row, col); //행렬 a에 대해 동적으로 할당한 메모리를 해제한다.
            free_matrix(matrix_b, row, col); //행렬 b에 대해 동적으로 할당한 메모리를 해제한다.
        	break;
        default: // 위의 문자가 아닌 다른 문자가 출력 될 경우
        	printf("\n       >>>>>   Concentration!!   <<<<<     \n");
    		break;
        }

    }while(command != 'q' && command != 'Q'); // q가 나올 때 까지 위에 반복문 지속

    return 0;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
	int i; // 루프용 변수

	if(row <= 0 || col <=0) // row나 col이 0이면 아래 루프 연산을 돌리지 않고 오류문장 출력 후 메인으로 돌아간다. 이하 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	int** matrix_cre = (int**)malloc(sizeof(int*) * row); // 이중포인터로 변수를 선언하고 입력받은 행의 크기 * int형 포인터의 크기(8바이트)만큼 이중포인터로 동적 메모리를 할당한다. -> 배열의 주소를 저장할 부분을 만든다.

	for(i=0; i<row; i++) // 입력받은 행 크기가 될 때 까지 루프
	{
		matrix_cre[i] = (int*)malloc(sizeof(int) * col); // int형의 크기(4바이트) * 열의 크기 만큼 포인터로 동적 메모리를 할당한다. -> 배열의 값을 저장할 부분을 만든다.
	}
	if(matrix_cre == NULL) // 생성이 정상적으로 실행되지 않아 배열이 NULL이라면 오류문장 출력 후 메인으로 돌아간다. 이하 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	return matrix_cre; // 2차원 배열이 된 변수를 리턴한다.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
	int i, j; // 루프용 변수

	for(i=0; i<row; i++) // 행 탐색 루프
	{
		for(j=0; j<col; j++) // 열 탐색 루프
		{
			printf("%d \t", matrix[i][j]); // 배열 출력 문장
		}
		printf("\n");
	}
	printf("\n");
}

/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	free(matrix); // 받은 배열인 동적 메모리를 해제한다.
	
	if(matrix == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
}

/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
	int i, j; // 루프용 변수

	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // 행 탐색 루프
	{
		for(j=0; j<col; j++) // 열 탐색 루프
		{
			matrix[i][j] = rand()%20; // 배열에 20미만의 무작위 정수를 저장한다
		}
	}
	if(matrix == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	return 0;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	int i, j; // 루프용 변수

	int** matrix_add = create_matrix(row, col); // 입력받은 크기를 가지고 2차원 배열 형태로 동적메모리 할당된 변수를 선언한다.

	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // 행 탐색 루프
	{
		for(j=0; j<col; j++) // 열 탐색 루프
		{
			matrix_add[i][j] = matrix_a[i][j] + matrix_b[i][j]; // 배열의 덧셈 연산
		}
	}
	if(matrix_add == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_add, row, col); // 연산 결과 출력
	free_matrix(matrix_add, row, col); // 앞서 할당된 동적메모리를 해제한다.

	return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	int i, j; // 루프용 변수
	int** matrix_sub = create_matrix(row, col); // 입력받은 크기를 가지고 2차원 배열 형태로 동적메모리 할당된 변수를 선언한다.

	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // 행 탐색 루프
	{
		for(j=0; j<col; j++) // 열 탐색 루프
		{
			matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j]; // 배열의 뺄셈 연산
		}
	}
	if(matrix_sub == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_sub, row, col); // 연산 결과 출력
	free_matrix(matrix_sub, row, col); // 앞서 할당된 동적메모리를 해제한다.

	return 0;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
	int i, j; // 루프용 변수

	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // 행 탐색 루프
	{
		for(j=0; j<col; j++) // 열 탐색 루프
		{
			matrix_t[i][j] = matrix[j][i]; // 배열을 전치하는 연산
		}
	}
	if(matrix_t == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_t, row, col); // 연산 결과 출력

	return 0;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
	int i, j, k; // 루프용 변수
	int cal; // 중간 연산을 저장하는 변수
	int** matrix_axt = create_matrix(row, row); // 입력받은 크기를 가지고 2차원 배열 형태로 동적메모리 할당된 변수를 선언한다.

	if(row <= 0 || col <=0) // 전처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++)
	{
		for(j=0; j<row; j++)
		{
			cal = 0; // 루프 안에서 초기화 해서 재사용 한다.
			for(k=0; k<col; k++)
			{
				cal += matrix_a[i][k] * matrix_t[k][j]; // 중간 연산 값을 cal에 저장한다.
			}
			matrix_axt[i][j] = cal; // 중간 연산이 끝난 cal을 저장한다.
		}
	}
	if(matrix_axt == NULL) // 후처리기
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_axt, row, row); // 연산 결과 출력
	free_matrix(matrix_axt, row, row); // 앞서 할당된 동적메모리를 해제한다.

	return 0;
}

