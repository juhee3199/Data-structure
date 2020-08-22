#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 스택 특성상 uprotate를 할때 top만 조회할 수 있음. for문사용xx

//1.
/*
int N, top;

void push(char *stack, char c) {
	if (top >= N-1) {
		printf("Stack FULL \n");
		return;
	}

	top++;
	stack[top] = c;
	
}
char pop(char *stack) {
	char e;

	if (top <= -1) {				
		printf("Stack Empty \n");
		return;
	}

	e = stack[top];
	top--;
	return e;

}
void peek(char *stack){
	if (top <= -1) {				
		printf("Stack Empty \n");
		return;
	}

	printf("%c \n", stack[top]);
}
void duplicate(char *stack) {
	char e;

	if (top >= N) {
		printf("Stack FULL \n");
		return;
	}

	e = pop(stack);
	push(stack, e);
	push(stack, stack[top]);
	
}
void upRotate(char *stack, int n) {
	int i = 0;
	char imsi;

	if (n > top + 1) {
		return;
	}

	imsi = stack[top];

	while (i != n-1) {
		stack[top - i] = stack[top - i - 1];
		i++;
	}
	stack[top - i] = imsi;		// stack[top-n-1] = stack[top]

}
void downRotate(char *stack, int n) {
	int i;
	char imsi;

	if (n > top + 1) {
		return;
	}

	imsi = stack[top - n + 1];

	for (i = top - n + 1; i < top; i++) {
		stack[i] = stack[i + 1];
	}

	stack[top] = imsi;		// stack[top] = stack[top - n + 1];

}
void print(char *stack) {
	int i;
	for (i = top; i >= 0; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

int main() {
	int i, n, cnt;			//cnt는 연산의 개수.		
	char *stack, oper[10],  c;

	scanf("%d", &N);
	stack = (char *)malloc(sizeof(char)* N);
	top = -1;

	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++) {
		scanf("%s", oper);

		if (strcmp(oper,"POP")==0) {
			pop(stack);
		}
		else if (strcmp(oper,"PUSH") == 0) {
			scanf(" %c", &c);
			push(stack, c);
		}
		else if (strcmp(oper,"PEEK") == 0) {
			peek(stack);
		}
		else if (strcmp(oper,"DUP") == 0) {
			duplicate(stack);
		}
		else if (strcmp(oper,"UpR") == 0) {
			scanf("%d", &n);
			upRotate(stack, n);
		}
		else if (strcmp(oper,"DownR") == 0) {
			scanf("%d", &n);
			downRotate(stack, n);
		}
		else if (strcmp(oper,"PRINT") == 0) {
			print(stack);
		}

	}

}
*/

//2.
/*
char *stack;
int top;

void push(char c) {

	top++;
	stack[top] = c;
}
char pop() {
	char e;

	e = stack[top];
	top--;
	return e;
}

int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isBalanced(char *Equation) {
	char popelem;
	int len;
	len = strlen(Equation);

	for (int i = 0; i < len; i++) {
		if ((Equation[i] == '(') || (Equation[i] == '{') || (Equation[i] == '[')) {
			push(Equation[i]);
		}

		else if ((Equation[i] == ')') || (Equation[i] == '}') || (Equation[i] == ']')) {
			if (isEmpty() == 1) {	//stack에 아무 원소도 없는지 확인.
				return 0;
			}

			popelem = pop();

			if (Equation[i] == ')') {
				if (popelem != '(') {
					return 0;
				}
			}

			else if (Equation[i] == '}') {
				if (popelem != '{') {
					return 0;
				}
			}

			else if (Equation[i] == ']') {
				if (popelem != '[') {
					return 0;
				}
			}
		}
	}
	return isEmpty();

}
int main() {
	int count = 0, len;
	char *Equation;

	Equation = (char*)malloc(sizeof(char) * 1000);
	stack = (char*)malloc(sizeof(char) * 1000);
	top = -1;


	//gets(Equation);
	scanf("%[^\n]s", Equation);
	len = strlen(Equation);

	for (int i = 0; i < len; i++) {

		if ((Equation[i] == '(') || (Equation[i] == '{') || (Equation[i] == '[') || (Equation[i] == ')') || (Equation[i] == '}') || (Equation[i] == ']')) {
			count++;
		}
	}

	if (isBalanced(Equation) == 1) {
		printf("OK_%d", count);
	}
	else {
		printf("Wrong_%d", count);
	}

	free(Equation);
	free(stack);
}
*/