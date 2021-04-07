/*
 * postfix.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10 //�ִ� ������ ũ�� 10�� ���� 
#define MAX_EXPRESSION_SIZE 20 // ������ ���� �ִ� ũ�� ��� 20�� ���� 

typedef enum{ 
	lparen = 0,  
	rparen = 9,  
	times = 7,  
	divide = 6,  
	plus = 5, 
	minus = 4,   
	operand = 1 
} precedence; // ������ �� �켱���� �� ����ü 

char infixExp[MAX_EXPRESSION_SIZE];  // ����ǥ��� ���� �迭 
char postfixExp[MAX_EXPRESSION_SIZE]; // ����ǥ��� ���� �迭 
char postfixStack[MAX_STACK_SIZE];	// ����ǥ��� �������� ����� �迭 
int evalStack[MAX_STACK_SIZE]; // ����ǥ��� ���� �������� ����� �迭 

int postfixStackTop = -1;  // ����ǥ��� ������ top���� ����� ������  -1�� �ʱ�ȭ 
int evalStackTop = -1;	//  ����ǥ��� ���� ������ top���� ����� ������ -1�� �ʱ�ȭ 

int evalResult = 0;	// ����ǥ��� ������ ����� ������ ������ 0���� �ʱ�ȭ 

void postfixpush(char x); // ����ǥ��Ŀ� ���ڸ� push �� �Լ� 
char postfixPop(); // ����ǥ��Ŀ� pop�� �� �Լ� 
void evalPush(int x); // ����ǥ��� ���꿡 ������ push �� �Լ� 
int evalPop(); // ����ǥ��� ���꿡 pop�� �� �Լ� 
void getInfix(); // ����ǥ����� ����ڷκ��� ���� �Լ� 
precedence getToken(char symbol); // ��ǲ�� ���������� �ǿ��������� �з� �� ������ �Լ� 
precedence getPriority(char x); // ��ǲ���� �������� �켱������ �з� �� ������ �Լ� 
void charCat(char* c); // ��ǲ�� ����ǥ��� �迭�� �����ϴ� �Լ� 
void toPostfix(); // ����ǥ����� ����ǥ������� �ٲٴ� �Լ� 
void debug(); // ������ ���� �迭�� ������ ���� ����ϴ� �Լ� 
void reset(); // ��� ���� �ʱ�ȭ�ϴ� �Լ� 
void evaluation(); // ����ǥ������� �ٲ� ���� �����ϴ� �Լ� 

int main()
{
	char command; // ����ڷκ��� �޴��� �Է¹��� ���� 

	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix(); // ����ڷκ��� ����ǥ��� �Է� ���� 
			break;
		case 'p': case 'P':
			toPostfix(); // �Է¹��� ����ǥ����� ����ǥ������� ���� 
			break;
		case 'e': case 'E':
			evaluation(); // ����ǥ����� ����
			break;
		case 'd': case 'D':
			debug(); // ���� �迭�� ���� �� ��� 
			break;
		case 'r': case 'R':
			reset(); // ��� �� �ʱ�ȭ 
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // Q�� ���� �� ���� ���� �ݺ� 

	return 1;
}

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x; // postfixStackTop�� 1�� ���� �迭 ��ġ�� x�� ����  
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1) // postfixStackTop == -1�� ��� ������ �� �����̹Ƿ� pop�� �Ұ��� �� null�� ���� 
        return '\n';
    else {
    	x = postfixStack[postfixStackTop--]; // x�� postfixStackTop�� �迭 ��ġ�� ���� �����ϰ� postfixStackTop�� 1�� ���� 
   }
    return x;
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x; // evalStackTop�� 1�� ���� �迭 ��ġ�� 1�� ���ϰ� x�� ���� 
}

int evalPop()
{
    if(evalStackTop == -1) // evalStackTop == -1�� ��� ������ �� �����̹Ƿ� pop�� �Ұ��� �� null�� ����
        return -1;
    else
        return evalStack[evalStackTop--]; // evalStackTop�� �迭 ��ġ�� ���� �����ϰ� evalStackTop�� 1�� ���� 
}

void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp); // ����ڷκ��� ����������� �Է¹޾� ���� 
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen; // symbol�� ���� ����ǥ ���� �����ϰ�� �ش� ������ �����ϴ� ����  
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand; // �� �ܿ��� operand�� ���� 
	}
}

precedence getPriority(char x)
{
	return getToken(x); //�Է¹��� ���ڸ� getToken�� ���ǿ� ���� �ٸ� ���� ���� 
}
void charCat(char* c)
{
	if (postfixExp == '\0') // postfixExp�� null�̶�� c�� ����� 
		strncpy(postfixExp, c, 1);
	else // �� ���� ��� c�� �̾� ���� 
		strncat(postfixExp, c, 1);
}

void toPostfix()
{
   char *exp = infixExp; // �����ͺ��� exp�� infixExp�� ���� 
   char x; // ����� ���� 
   char pop; // pop �� ����� ���� 

   while(*exp != NULL) 
   {
    	x = *exp;
    	
		if(getPriority(x) == operand) // �ǿ����� �� ��� postfixExp�� x�� ���� 
			charCat(&x);
		
		else if(getPriority(x) == 'rparen') // ')'�� ��� '('�� ��Ÿ�� �� ���� pop�ϰ� p�� �����ϰ� p�� postfixExp�� push 
		{
        	while(postfixStack[postfixStackTop] == 'lparen')
			{
				pop = postfixPop();
    			charCat(&pop);
			}
			postfixPop(); // while ������ ���� '('�� pop  
    	}
    	else if(getPriority(x) == 'lparen') // '('�� ��� x�� push�ϰ� 1�� ���� 
     	      postfixPush(x++);
    	else if(getPriority(postfixStack[postfixStackTop]) >= getPriority(x))
    	{
			pop = postfixPop();
        	charCat(&pop);
    		postfixPush(x);
    	}
		else
    		postfixPush(x);
		exp++;
	}	
	while (postfixStackTop!= -1)
	{
		pop = postfixPop();
		charCat(&pop);
	}
}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	char *exp = postfixExp; 
	int x;
	int op1, op2; 

	while (*exp != '\0') 
	{
		x = *exp; 
		
		if (getPriority(x) == operand) 
		{
			x = x - '0';
			evalPush(x);
		}
		else 
		{
			op2 = evalPop(); 
			op1 = evalPop(); 
			switch (getPriority(x))
			{
			case times:
				evalPush(op1 * op2); 
				break;
			case divide:
				evalPush(op1 / op2); 
				break;
			case plus:
				evalPush(op1 + op2); 
				break;
			case minus:
				evalPush(op1 - op2); 
				break;
			}
		}
		exp++; 
	}
	//evalResult = evalPop();	
	evalResult = evalStack[evalStackTop]; //evalstack�迭�� top�� �������� �����ƴ� 
}

