#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct List_Node {
	int elem;
	struct List_Node* next;
}listNode;
typedef struct {
	listNode* H;
}Header;

Header* initialize(Header* LIST) {
	LIST->H = (listNode *)malloc(sizeof(listNode));

	LIST->H->next = NULL;

	return LIST;
}
void addLast(Header *k, int e) {
	listNode *t = (listNode *)malloc(sizeof(listNode));

	listNode *p;				//임시
	p = k->H;
	while (p->next != NULL) {
		p = p->next;
	}

	t->elem = e;
	t->next = NULL;

	p->next = t;
	return;
}
int subset(Header *A, Header *B) {
	listNode *p;
	listNode *q;
	
	p = A->H->next;
	q = B->H->next;

	if (p == NULL) {
		return 0;
	}
	else if (q == NULL) { // A는 NULL이 아니고, B가 NULL일때.
		return p->elem;
	}
	
	while (p != NULL || q != NULL){
		if (p->elem > q->elem) {	//q의 다음 원소에 p가 존재하는지 확인
			if (q->next == NULL) {
				return p->elem;
			}
			q = q->next;
		}

		else if (p->elem < q->elem) {//q에 p의 해당 원소가 존재하지 않음.
			return p->elem;
		}

		else if (p->elem == q->elem) {
			if (p->next == NULL) {
				return 0;
			}
			p = p->next;
			q = q->next;
		}
	}
}
int main() {
	int n, i, e;
	Header  *A, *B;
	A = (Header*)malloc(sizeof(Header));
	B = (Header*)malloc(sizeof(Header));

	A = initialize(A);
	B = initialize(B);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {		
		scanf("%d", &e);
		addLast(A, e);
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++) {		
		scanf("%d", &e);
		addLast(B, e);
	}

	printf("%d", subset(A, B));
}

*/


//2.
/*
typedef struct List_Node {
	int elem;
	struct List_Node* next;
}listNode;
typedef struct {
	listNode* H;
}Header;

Header* initialize(Header* LIST) {
	LIST->H = (listNode *)malloc(sizeof(listNode));

	LIST->H->next = NULL;

	return LIST;
}
void addLast(Header *k, int e) {
	listNode *t = (listNode *)malloc(sizeof(listNode));

	listNode *p;				//임시
	p = k->H;
	while (p->next != NULL) {
		p = p->next;
	}

	t->elem = e;
	t->next = NULL;

	p->next = t;
	return;
}

Header* union_set(Header *A, Header *B) {
	Header* result = (Header *)malloc(sizeof(Header));;
	listNode *p;
	listNode *q;

	result = initialize(result);
	p = A->H->next;
	q = B->H->next;

	while (p != NULL && q != NULL) {

		if (p->elem < q->elem) {
			addLast(result, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem) {
			addLast(result, q->elem);
			q = q->next;
		}
		else {		//p.elem == q.elem
			addLast(result, p->elem);
			p = p->next;
			q = q->next;
		}
	}

	while (p != NULL) {
		addLast(result, p->elem);
		p = p->next;
	}
	while (q != NULL) {
		addLast(result, q->elem);
		q = q->next;
	}

	return result;
}
Header* intersect(Header *A, Header *B) {
	Header* result = (Header *)malloc(sizeof(Header));;
	listNode *p;
	listNode *q;

	result = initialize(result);
	p = A->H->next;
	q = B->H->next;

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			p = p->next;
		}
		else if (p->elem > q->elem) {
			q = q->next;
		}
		else {	//p.elem == q.elem
			addLast(result, p->elem);
			p = p->next;
			q = q->next;
		}
	}
	return result;
}
int main() {
	int n, i, e;
	Header  *A, *B;
	A = (Header*)malloc(sizeof(Header));
	B = (Header*)malloc(sizeof(Header));

	A = initialize(A);
	B = initialize(B);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		addLast(A, e);
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		addLast(B, e);
	}

	Header *set1, *set2;
	set1 = union_set(A, B);
	set2 = intersect(A, B);

	listNode *p;
	p = set1->H->next;
	if (p == NULL) {
		printf(" %d\n", 0);
	}
	else {
		while (p != NULL) {
			printf(" %d", p->elem);
			p = p->next;
		}
		printf("\n");
	}
	
	p = set2->H->next;
	if (p == NULL) {
		printf(" %d", 0);
	}
	else {
		while (p != NULL) {
			printf(" %d", p->elem);
			p = p->next;
		}
	}
}
*/