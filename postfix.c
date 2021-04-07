/*
 * postfix.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10 //최대 스택의 크기 10을 정의 
#define MAX_EXPRESSION_SIZE 20 // 연산자 포함 최대 크기 상수 20을 정의 

typedef enum{ 
	lparen = 0,  
	rparen = 9,  
	times = 7,  
	divide = 6,  
	plus = 5, 
	minus = 4,   
	operand = 1 
} precedence; // 연산자 별 우선순위 용 구조체 

char infixExp[MAX_EXPRESSION_SIZE];  // 중위표기식 저장 배열 
char postfixExp[MAX_EXPRESSION_SIZE]; // 후위표기식 저장 배열 
char postfixStack[MAX_STACK_SIZE];	// 후위표기식 스택으로 사용할 배열 
int evalStack[MAX_STACK_SIZE]; // 후위표기식 연산 스택으로 사용할 배열 

int postfixStackTop = -1;  // 후위표기식 스택의 top으로 사용할 변수를  -1로 초기화 
int evalStackTop = -1;	//  후위표기식 연산 스택의 top으로 사용할 변수를 -1로 초기화 

int evalResult = 0;	// 후위표기식 연산의 결과를 저장할 변수를 0으로 초기화 

void postfixpush(char x); // 후위표기식에 문자를 push 할 함수 
char postfixPop(); // 후위표기식에 pop을 할 함수 
void evalPush(int x); // 후위표기식 연산에 정수를 push 할 함수 
int evalPop(); // 후위표기식 연산에 pop을 할 함수 
void getInfix(); // 중위표기식을 사용자로부터 받을 함수 
precedence getToken(char symbol); // 인풋이 연산자인지 피연산자인지 분류 후 리턴할 함수 
precedence getPriority(char x); // 인풋받은 연산자의 우선순위를 분류 후 리턴할 함수 
void charCat(char* c); // 인풋을 중위표기식 배열에 저장하는 함수 
void toPostfix(); // 중위표기식을 후위표기식으로 바꾸는 함수 
void debug(); // 현재의 여러 배열과 정수의 값을 출력하는 함수 
void reset(); // 모든 값을 초기화하는 함수 
void evaluation(); // 후위표기식으로 바뀐 식을 연산하는 함수 

int main()
{
	char command; // 사용자로부터 메뉴를 입력받을 변수 

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
			getInfix(); // 사용자로부터 중위표기식 입력 받음 
			break;
		case 'p': case 'P':
			toPostfix(); // 입력받은 중위표기식을 후위표기식으로 변경 
			break;
		case 'e': case 'E':
			evaluation(); // 후위표기식을 연산
			break;
		case 'd': case 'D':
			debug(); // 현재 배열과 변수 값 출력 
			break;
		case 'r': case 'R':
			reset(); // 모든 값 초기화 
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // Q가 나올 때 까지 루프 반복 

	return 1;
}

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x; // postfixStackTop에 1을 더한 배열 위치에 x를 저장  
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1) // postfixStackTop == -1일 경우 스택이 빈 상태이므로 pop이 불가능 해 null을 리턴 
        return '\n';
    else {
    	x = postfixStack[postfixStackTop--]; // x에 postfixStackTop인 배열 위치의 값을 저장하고 postfixStackTop에 1을 뺀다 
   }
    return x;
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x; // evalStackTop에 1을 더한 배열 위치에 1을 더하고 x를 저장 
}

int evalPop()
{
    if(evalStackTop == -1) // evalStackTop == -1일 경우 스택이 빈 상태이므로 pop이 불가능 해 null을 리턴
        return -1;
    else
        return evalStack[evalStackTop--]; // evalStackTop인 배열 위치의 값을 리턴하고 evalStackTop에 1을 뺀다 
}

void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp); // 사용자로부터 중위연산식을 입력받아 저장 
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen; // symbol이 작은 따옴표 내의 문자일경우 해당 조건을 충족하는 리턴  
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand; // 그 외에는 operand를 리턴 
	}
}

precedence getPriority(char x)
{
	return getToken(x); //입력받은 문자를 getToken의 조건에 따라 다른 값을 리턴 
}
void charCat(char* c)
{
	if (postfixExp == '\0') // postfixExp가 null이라면 c를 덮어씌움 
		strncpy(postfixExp, c, 1);
	else // 그 외의 경우 c를 이어 붙임 
		strncat(postfixExp, c, 1);
}

void toPostfix()
{
   char *exp = infixExp; // 포인터변수 exp에 infixExp를 저장 
   char x; // 연산용 변수 
   char pop; // pop 값 저장용 변수 

   while(*exp != NULL) 
   {
    	x = *exp;
    	
		if(getPriority(x) == operand) // 피연산자 일 경우 postfixExp에 x를 저장 
			charCat(&x);
		
		else if(getPriority(x) == 'rparen') // ')'일 경우 '('가 나타날 때 까지 pop하고 p에 저장하고 p를 postfixExp에 push 
		{
        	while(postfixStack[postfixStackTop] == 'lparen')
			{
				pop = postfixPop();
    			charCat(&pop);
			}
			postfixPop(); // while 루프를 나온 '('를 pop  
    	}
    	else if(getPriority(x) == 'lparen') // '('일 경우 x를 push하고 1을 더함 
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
	evalResult = evalStack[evalStackTop]; //evalstack배열의 top에 연산결과가 축적됐다 
}

