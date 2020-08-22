/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Listnode{
	int data;
	struct Listnode *left;
	struct Listnode *right;
}listnode;

listnode* initialize(int data, listnode *left, listnode *right) {          //초기화
	listnode *root;
	root = (listnode*)malloc(sizeof(listnode));

	root->data = data;
	root->left = left;
	root->right = right;

	return root;
}
listnode* addnode(int data) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;
}

// 두개의 자식노드와 연결.
listnode* addParent(int data, listnode *left, listnode *right) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->data = data;
	p->left = left;
	p->right = right;

	return p;
}
int isInternal(listnode *loc) {
	if (loc->left != NULL && loc->right != NULL) {
		return 2;
	}
	else if (loc->left != NULL && loc->right == NULL) {
		return -1;  //왼쪽 자식만 존재
	}
	else if (loc->left == NULL && loc->right != NULL) {
		return 1;	// 오른쪽 자식만 존재
	}
	else {
		return 0;
	}
}
int main() {
	int n;
	listnode *loc[8];  //F

	loc[0] = initialize(20, NULL, NULL);	// tree의 root

	loc[7] = addnode(80);
	loc[6] = addnode(130);
	loc[5] = addParent(120,loc[6], loc[7]);
	loc[0]->right = loc[6];

	loc[4] = addnode(90);
	loc[3] = addnode(70);
	loc[1] = addParent(30, loc[3], loc[4]);
	loc[0]->left = loc[1];

	loc[2] = addParent(50, NULL, loc[5]);
	loc[0]->right = loc[2];

	scanf("%d", &n);
	if (n>8 || n<1) {
		printf("%d\n", -1);
		return -1;
	}

	if (isInternal(loc[n-1])==2) {
		printf("%d ", loc[n-1]->data);
		printf("%d ", loc[n-1]->left->data);
		printf("%d\n", loc[n-1]->right->data);
	}
	else if (isInternal(loc[n-1]) == -1) {	//왼쪽자식만 존재
		printf("%d ", loc[n-1]->data);
		printf("%d\n", loc[n-1]->left->data);
	}
	else if (isInternal(loc[n-1]) == 1) {		// 오른쪽자식만 존재
		printf("%d ", loc[n-1]->data);
		printf("%d\n", loc[n-1]->right->data);
	}
	else {									// 자식이 존재하지 않음.
		printf("%d ", loc[n-1]->data);
	}
}


*/