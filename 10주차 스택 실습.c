#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.
/*
typedef struct Stack {
	int top;
	int sign;
}stackSign;

void push(char *stack, char value, stackSign* st);
char pop(char *stack, stackSign* st);
int priority(char *infix, int i, stackSign* st);

int main() {

	int N, n = 0;
	char *infix = NULL;
	char tmp[100], postfix[100], stack[100];

	stackSign st;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		n = 0;
		st.top = -1;
		st.sign = 0;

		for (int j = 0; j < 100; j++) {
			postfix[j] = '\0';
			stack[j] = '\0';
		}

		scanf("%s", tmp);
		getchar();

		infix = malloc(sizeof(char) * ((int)strlen(tmp) + 1));
		strcpy(infix, tmp);

		// 우선순위를 판별하여 stack에 저장하고 pop하면서 이를 postfix에 저장.
		// postfix에 후위수식연산을 순서대로 저장하고 출력

		for (int j = 0; j < (int)strlen(infix); j++) {

			if (infix[j] == '(')							//괄호가 나오면 스택에 저장
				push(stack, infix[j], &st);

			else if (infix[j] == ')') {
				while (stack[st.top] != '(')			//stack에 저장된 괄호사이의 연산을 postfix에 넣고, stack에서 pop
					postfix[n++] = pop(stack, &st);
				pop(stack, &st);						//pop '('
			}

			else if (priority(infix, j, &st) == 6)			//우선순위가 6이면 stack에 push
				push(stack, infix[j], &st);

			else if (priority(infix, j, &st) == 0)			// 숫자. 피연산자
				postfix[n++] = infix[j];

			else {
				if (st.sign == 1)
					postfix[n++] = pop(stack, &st);
				else {										//연산자를 비교하여 우선순위 연산자를 postfix에 저장.				
					while ((st.top != -1) && (priority(infix, j, &st) <= priority(stack, st.top, &st)))
						postfix[n++] = pop(stack, &st);
				}
				if ((priority(infix, j, &st) == 1) || (priority(infix, j, &st) == 2))
					push(stack, infix[j++], &st);
				push(stack, infix[j], &st);
			}
		}
		while (st.top != -1)
			postfix[n++] = pop(stack, &st);
		printf("%s\n", postfix);
	}

	free(infix);
	return 0;
}

void push(char *stack, char value, stackSign *st) {
	(st->top)++;
	stack[st->top] = value;
}

char pop(char *stack, stackSign *st) {
	return stack[(st->top)--];
}

// 연산자의 우선순위를 반환.
// 피연산자는 return 0
int priority(char *infix, int i, stackSign *st) {
	if ((st->top != i) && (i == 0) && ((infix[i] == '+') || (infix[i] == '-'))) {
		st->sign = 1;
		return 6;
	}
	else if ((st->top != -1) && ((infix[i] == '+') || (infix[i] == '-')) && priority(infix, i - 1, st) != 0)
		return 6;

	else if (infix[i] == '!')
		return 6;

	else if (infix[i] == '*' || infix[i] == '/')
		return 5;

	else if (infix[i] == '+' || infix[i] == '-')
		return 4;

	else if (infix[i] == '>' || infix[i] == '<')
		return 3;

	else if (infix[i] == '&')
		return 2;

	else if (infix[i] == '|')
		return 1;

	else              //피연산자 operand                    
		return 0;
}
*/





//2. 
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stackSign {
	int top;
}stackSign;

void push(char *stack, char value, stackSign *st);
char pop(char *stack, stackSign *st);
int priority(char cal, stackSign *st);

int main() {
	int N, num1, num2;
	char *infix = NULL;
	char tmp[100], stack[100], imsi;
	stackSign st;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		st.top = -1;

		scanf("%s", tmp);
		getchar();

		infix = malloc(sizeof(char) * ((int)strlen(tmp) + 1));
		strcpy(infix, tmp);

		for (int i = 0; i < (int)strlen(infix); i++) {
			if (priority(infix[i], &st) == 0)
				push(stack, infix[i] - '0', &st);
			else {
				if (priority(infix[i], &st) == 4) {
					imsi = pop(stack, &st) * pop(stack, &st);
					push(stack, imsi, &st);
				}
				else if (priority(infix[i], &st) == 3) {
					num1 = pop(stack, &st);
					num2 = pop(stack, &st);
					push(stack, num2 / num1, &st);
				}
				else if (priority(infix[i], &st) == 2) {
					imsi = pop(stack, &st) + pop(stack, &st);
					push(stack, imsi, &st);
				}
				else if (priority(infix[i], &st) == 1) {
					num1 = pop(stack, &st);
					num2 = pop(stack, &st);
					push(stack, num2 - num1, &st);
				}
			}
		}
		printf("%d\n", pop(stack, &st));
	}
	free(infix);
	return 0;
}

void push(char *stack, char value, stackSign *st) {
	(st->top)++;
	stack[st->top] = value;
}
char pop(char *stack, stackSign *st) {
	return stack[(st->top)--];
}

int priority(char cal, stackSign *st) {
	if (cal == '*')
		return 4;
	else if (cal == '/')
		return 3;
	else if (cal == '+')
		return 2;
	else if (cal == '-')
		return 1;
	else
		return 0;
}
*/