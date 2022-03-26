#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col); // ���� �޸� �Ҵ��� �� ���������ͷ� ������ �� �Լ� ����.
void print_matrix(int** matrix, int row, int col); // �迭�� ������� �Լ��� ����.
int free_matrix(int** matrix, int row, int col); // �迭�� �ʱ�ȭ�ϴ� �Լ��� ����.
int fill_data(int** matrix, int row, int col); // �迭�� ���� �����ϴ� �Լ��� ����.
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col); // �迭 a, b�� ���ϴ� ������ �ϴ� �Լ��� ����.
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col); // �迭 a, b�� ���� ������ �ϴ� �Լ��� ����.
int transpose_matrix(int** matrix, int** matrix_t, int row, int col); // �迭 a�� ��ġ�ϴ� ������ �ϴ� �Լ��� ����.
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col); // �迭 a, b�� ���ϴ� ������ �ϴ� �Լ��� ����.
int main()
{
    char command; //�޴��� ���� ���� ����
    printf("[----- [������]  [2018038036] -----]\n");

    int row, col; //�迭�� ��� ���� ũ�⸦ ���� ����
    srand(time(NULL)); //���ؽð����κ��� �ʸ� �޾� ������ ���� �õ� ����

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); // ����ڷ� ���� ��, ���� ũ�� �Է¹���
    int** matrix_a = create_matrix(row, col); // ����ڷ� ���� �Է¹��� ũ�⸸ŭ �����޸𸮸� �Ҵ� �� ���� ������ ������ ����
    int** matrix_b = create_matrix(row, col); // ����ڷ� ���� �Է¹��� ũ�⸸ŭ �����޸𸮸� �Ҵ� �� ���� ������ ������ ����
    int** matrix_a_t = create_matrix(col, row); // ����ڷ� ���� �Է¹��� ũ�⸸ŭ �����޸𸮸� �Ҵ� �� ���� ������ ������ ����
	printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;} // ���������� �����Ǿ����� ���� Ȯ��

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
        scanf(" %c", &command); // ����ڷκ��� �޴� �Է¹���
		printf("\n");
        switch(command) //�Է¹��� ���ڷ� �Ʒ� ������ ������
        {
        case 'z': case 'Z': // �Է� ���ڰ� z�� ���
            printf("Matrix Initialized\n");
            printf("matrix_a\n");
            fill_data(matrix_a, row, col); //������ ����� ��ҿ� 20�̸��� ���� ���� ����
            print_matrix(matrix_a, row, col); //������ ���� ����� ����� ���
            printf("matrix_b\n");
            fill_data(matrix_b, row, col); //������ ����� ��ҿ� 20�̸��� ���� ���� ����
            print_matrix(matrix_b, row, col); //������ ���� ����� ����� ���
            break;
        case 'p': case 'P': // �Է� ���ڰ� p�� ���
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col); // ��� a ���
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col); // ��� b ���
            break;
        case 'a': case 'A': // �Է� ���ڰ� a�� ���
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col); // ��� a,b�� ���ϰ� ����� ���
            break;
        case 's': case 'S': // �Է� ���ڰ� s�� ���
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col); // ��� a���� b�� ���� ����� ����Ѵ�.
            break;
        case 't': case 'T': // �Է� ���ڰ� t�� ���
            printf("Transpose matrix_a \n");
            printf("matrix_a_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row); // ��� a�� ���� ��ĥ����� ����� ����Ѵ�.
            break;
        case 'm': case 'M': // �Է� ���ڰ� m�� ���
            printf("Multiply matrix_a with transposed matrix_a \n");
            printf("matrix_a_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row); //�������� �ϱ� �� ��ġ ����� ����Ѵ�.
            printf("matrix_a * matrix_a_t\n");
            multiply_matrix(matrix_a, matrix_a_t, row, col); //�������� ����� ����Ѵ�.
        	//free_matrix(matrix_axt, row, row);
            break;
        case 'q': case 'Q': //q�� �Էµ� ���
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row); //��� a_t�� ���� �������� �Ҵ��� �޸𸮸� �����Ѵ�.
            free_matrix(matrix_a, row, col); //��� a�� ���� �������� �Ҵ��� �޸𸮸� �����Ѵ�.
            free_matrix(matrix_b, row, col); //��� b�� ���� �������� �Ҵ��� �޸𸮸� �����Ѵ�.
        	break;
        default: // ���� ���ڰ� �ƴ� �ٸ� ���ڰ� ��� �� ���
        	printf("\n       >>>>>   Concentration!!   <<<<<     \n");
    		break;
        }

    }while(command != 'q' && command != 'Q'); // q�� ���� �� ���� ���� �ݺ��� ����

    return 0;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
	int i; // ������ ����

	if(row <= 0 || col <=0) // row�� col�� 0�̸� �Ʒ� ���� ������ ������ �ʰ� �������� ��� �� �������� ���ư���. ���� ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	int** matrix_cre = (int**)malloc(sizeof(int*) * row); // ���������ͷ� ������ �����ϰ� �Է¹��� ���� ũ�� * int�� �������� ũ��(8����Ʈ)��ŭ ���������ͷ� ���� �޸𸮸� �Ҵ��Ѵ�. -> �迭�� �ּҸ� ������ �κ��� �����.

	for(i=0; i<row; i++) // �Է¹��� �� ũ�Ⱑ �� �� ���� ����
	{
		matrix_cre[i] = (int*)malloc(sizeof(int) * col); // int���� ũ��(4����Ʈ) * ���� ũ�� ��ŭ �����ͷ� ���� �޸𸮸� �Ҵ��Ѵ�. -> �迭�� ���� ������ �κ��� �����.
	}
	if(matrix_cre == NULL) // ������ ���������� ������� �ʾ� �迭�� NULL�̶�� �������� ��� �� �������� ���ư���. ���� ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	return matrix_cre; // 2���� �迭�� �� ������ �����Ѵ�.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
	int i, j; // ������ ����

	for(i=0; i<row; i++) // �� Ž�� ����
	{
		for(j=0; j<col; j++) // �� Ž�� ����
		{
			printf("%d \t", matrix[i][j]); // �迭 ��� ����
		}
		printf("\n");
	}
	printf("\n");
}

/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	free(matrix); // ���� �迭�� ���� �޸𸮸� �����Ѵ�.
	
	if(matrix == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
}

/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
	int i, j; // ������ ����

	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // �� Ž�� ����
	{
		for(j=0; j<col; j++) // �� Ž�� ����
		{
			matrix[i][j] = rand()%20; // �迭�� 20�̸��� ������ ������ �����Ѵ�
		}
	}
	if(matrix == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	return 0;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	int i, j; // ������ ����

	int** matrix_add = create_matrix(row, col); // �Է¹��� ũ�⸦ ������ 2���� �迭 ���·� �����޸� �Ҵ�� ������ �����Ѵ�.

	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // �� Ž�� ����
	{
		for(j=0; j<col; j++) // �� Ž�� ����
		{
			matrix_add[i][j] = matrix_a[i][j] + matrix_b[i][j]; // �迭�� ���� ����
		}
	}
	if(matrix_add == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_add, row, col); // ���� ��� ���
	free_matrix(matrix_add, row, col); // �ռ� �Ҵ�� �����޸𸮸� �����Ѵ�.

	return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	int i, j; // ������ ����
	int** matrix_sub = create_matrix(row, col); // �Է¹��� ũ�⸦ ������ 2���� �迭 ���·� �����޸� �Ҵ�� ������ �����Ѵ�.

	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // �� Ž�� ����
	{
		for(j=0; j<col; j++) // �� Ž�� ����
		{
			matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j]; // �迭�� ���� ����
		}
	}
	if(matrix_sub == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_sub, row, col); // ���� ��� ���
	free_matrix(matrix_sub, row, col); // �ռ� �Ҵ�� �����޸𸮸� �����Ѵ�.

	return 0;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
	int i, j; // ������ ����

	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++) // �� Ž�� ����
	{
		for(j=0; j<col; j++) // �� Ž�� ����
		{
			matrix_t[i][j] = matrix[j][i]; // �迭�� ��ġ�ϴ� ����
		}
	}
	if(matrix_t == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_t, row, col); // ���� ��� ���

	return 0;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
	int i, j, k; // ������ ����
	int cal; // �߰� ������ �����ϴ� ����
	int** matrix_axt = create_matrix(row, row); // �Է¹��� ũ�⸦ ������ 2���� �迭 ���·� �����޸� �Ҵ�� ������ �����Ѵ�.

	if(row <= 0 || col <=0) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}

	for(i=0; i<row; i++)
	{
		for(j=0; j<row; j++)
		{
			cal = 0; // ���� �ȿ��� �ʱ�ȭ �ؼ� ���� �Ѵ�.
			for(k=0; k<col; k++)
			{
				cal += matrix_a[i][k] * matrix_t[k][j]; // �߰� ���� ���� cal�� �����Ѵ�.
			}
			matrix_axt[i][j] = cal; // �߰� ������ ���� cal�� �����Ѵ�.
		}
	}
	if(matrix_axt == NULL) // ��ó����
	{
		printf("Check the sizes of row and col!\n");
		return NULL;
	}
	print_matrix(matrix_axt, row, row); // ���� ��� ���
	free_matrix(matrix_axt, row, row); // �ռ� �Ҵ�� �����޸𸮸� �����Ѵ�.

	return 0;
}

