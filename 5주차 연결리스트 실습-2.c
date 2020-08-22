/*


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_Node {
	int coef;
	int exp;
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
void appendTerm(Header *k, int c, int e) {
	listNode *t = (listNode *)malloc(sizeof(listNode));

	listNode *p;				//임시
	p = k->H;									
	while (p->next != NULL) {					
		p = p->next;
	}

	t->coef = c;
	t->exp = e;
	t->next = NULL;

	p->next = t;
	return;
}
Header* addpoly(Header *poly1, Header *poly2) {
	// result는 다항식 덧셈 결과를 저장하는 단일연결리스트.
	Header* result = (Header *)malloc(sizeof(Header));;
	result = initialize(result);

	int sum;
	listNode *i, *j;
	i = poly1->H->next;		//poly 헤더의 다음노드.
	j = poly2->H->next;

	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(result, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(result, j->coef, j->exp);
			j = j->next;
		}
		else{
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(result, sum, i->exp);
			}

			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(result, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(result, j->coef, j->exp);
		j = j->next;
	}
	return result;

}
int main() {
	int n, i, c, e;
	Header  *poly1, *poly2;
	poly1 = (Header*)malloc(sizeof(Header));
	poly2 = (Header*)malloc(sizeof(Header));

	poly1 = initialize(poly1);
	poly2 = initialize(poly2);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {		//poly1[0] 은 헤더.
		scanf("%d %d", &c, &e);
		appendTerm(poly1, c, e);
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++) {		//poly1[0] 은 헤더.
		scanf("%d %d", &c, &e);
		appendTerm(poly2, c, e);
	}

	Header *add;
	add = addpoly(poly1, poly2);

	listNode *p;
	p = add->H->next;
	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}
}
*/