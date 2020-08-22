#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct List_Node {
	char elem;					
	struct List_Node* prev;
	struct List_Node* next;
}listNode;
typedef struct {		
	listNode* H;
	listNode* T;
}linkedLIST;

linkedLIST* initialize(linkedLIST* LIST) {          //초기화
	LIST->H = (listNode *)malloc(sizeof(listNode));
	LIST->T = (listNode *)malloc(sizeof(listNode));

	LIST->H->next = LIST->T;
	LIST->T->prev = LIST->H;

	return LIST;
}
void add(linkedLIST *LIST, int r, char *e) {
	listNode *p, *q;
	int i;

	p = LIST->H;
	for (i = 1; i <= r; i++) {
		p = p->next;
	}

	q = (listNode *)malloc(sizeof(listNode));	//addNodeBefore(p, e)
	q->elem = *e;
	q->prev = p->prev;
	q->next = p;
	(p->prev)->next = q;
	p->prev = q;

}
char delete_node(linkedLIST *LIST, int r) {			// 삭제
	listNode *p;
	int i;
	char e;

	p = LIST->H;
	for (i = 1; i <= r; i++) {
		p = p->next;
	}
	e = p->elem;					//removeNode(p)
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;

	free(p);		
	return e;
}
char get(linkedLIST *LIST, int r) {
	listNode *p;
	int i;

	p = LIST->H;
	for (i = 1; i <= r; i++) {
		p = p->next;
	}
	if (p == NULL) {
		printf("invalid postion \n");
		return 0;
	}
	else {
		return p->elem;
	}

}
void print(linkedLIST *LIST) {		// traverse
	listNode *p;
	p = LIST->H->next;
	while (p != LIST->T) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main() {
	int n, i, r, cnt = 0;	
	char method, elem;
	char *e;
	e = (char *)malloc(sizeof(char));

	linkedLIST *LIST;
	LIST = (linkedLIST*)malloc(sizeof(linkedLIST));
	LIST = initialize(LIST);
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf(" %c", &method);

		if (method == 'A') {
			scanf("%d", &r);
			scanf(" %c", e);
			if (r < 1 || cnt+1 < r) {
				printf("invalid position\n");
			}
			else {
				add(LIST, r, e);
				cnt++;
			}
		}
		else if (method == 'D') {
			scanf("%d", &r);  
			if (r < 1 || cnt < r) {
				printf("invalid position\n");
			}
			else {
				elem = delete_node(LIST, r);
				cnt--;
			}
		}
		else if (method == 'G') {
			scanf("%d", &r);
			if (r < 1 || cnt < r) {
				printf("invalid position\n");
			}
			else {
				elem = get(LIST, r);
				printf("%c\n", elem);
			}			
		}
		else if (method == 'P') {
			print(LIST);
		}
	}
	free(e);
}
*/