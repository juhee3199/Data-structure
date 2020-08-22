#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.
/*
int q, f, r;
int *queue;

void initQueue();
void print();
void enqueue(int e);
void dequeue();

int main() {
	int n, e;
	char cmd;

	scanf("%d", &q);
	queue = (int *)malloc(sizeof(int) * q);
	initQueue();

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &cmd);

		if (cmd == 'I') {
			scanf("%d", &e);
			enqueue(e);
		}
		else if (cmd == 'D') {
			dequeue();
		}
		else if (cmd == 'P') {
			print();
		}
	}
	free(queue);
}
void initQueue() {
	f = 1;
	r = 1;
	for (int i = 0; i < q; i++) {
		queue[i] = 0;
	}
}
void print() {
	for (int i = 0; i < q; i++) {
		printf(" %d", queue[i]);
	}
	printf("\n");
}
void enqueue( int e) {
	if (f%q == (r+1)%q) {				//isFull()
		printf("overflow");
		print();
		//return;
	}
	queue[r] = e;
	r = (r + 1) % q;
}
void dequeue() {
	if (f%q == r%q) {					//isEmpty()
		printf("underflow");
		return;
	}
	queue[f] = 0;
	f = (f + 1) % q;
}
*/

// 2.
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_node {
	int elem;
	struct List_node* prev;
	struct List_node* next;
}node;

node *f, *r;
int queNum = 0;

node* init(node* deque, int e);
void add_front(node *deque, int e);
void add_rear(node *deque, int e);
int delete_front(node *deque);
int delete_rear(node *deque);
void print(node *deque);

node* init(node* deque, int e) {
	deque->elem = e;
	deque->prev = NULL;
	deque->next = NULL;

	f = deque;
	r = deque;

	return deque;
}
void add_front(node *deque, int e) {
	node *q = (node*)malloc(sizeof(node));

	q->elem = e;
	q->prev = NULL;
	q->next = f;

	f->prev = q;
	f = q;
}
void add_rear(node *deque, int e) {
	node *q = (node*)malloc(sizeof(node));

	q->elem = e;
	q->next = NULL;
	q->prev = r;

	r->next = q;
	r = q;
}
int delete_front(node *deque) {
	char e;
	node *q = (node*)malloc(sizeof(node));

	if (queNum == 0) {
		printf("underflow \n");
		exit(1);
	}
	else if (queNum == 1) {
		e = r->elem;
		free(q);
		return e;
	}
	e = f->elem;
	q = f;

	f = f->next;
	f->prev = NULL;

	free(q);
	return e;
}
int delete_rear(node *deque) {
	char e;
	node *q = (node*)malloc(sizeof(node));

	if (queNum == 0) {		//underflow
		printf("underflow \n");
		exit(1);
	}
	else if (queNum == 1) {
		e = r->elem;
		free(q);
		return e;
	}
	e = r->elem;
	q = r;

	r = r->prev;
	r->next = NULL;

	free(q);
	return e;
}
void print(node *deque) {
	node *p;
	p = f;
	while (p->next != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf(" %d", p->elem);
	printf("\n");
}
int main() {
	int n, e;
	char cmd[5];
	node *deque;

	deque = (node*)malloc(sizeof(node));
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %s", &cmd);

		if (strcmp(cmd,"AF") == 0) {
			scanf("%d", &e);
			if (queNum == 0) {
				deque = init(deque, e);
			}
			else {
				add_front(deque, e);
			}
			queNum++;
		}
		else if (strcmp(cmd, "AR") == 0) {
			scanf("%d", &e);
			if (queNum == 0) {
				deque = init(deque, e);
			}
			else {
				add_rear(deque, e);
			}
			queNum++;
		}
		else if (strcmp(cmd, "DF")==0) {
			e = delete_front(deque);
			queNum--;
		}
		else if (strcmp(cmd, "DR") == 0) {
			e = delete_rear(deque);
			queNum--;
		}
		else if (strcmp(cmd, "P") == 0) {
			print(deque);
		}
	}

	free(deque);
}

*/