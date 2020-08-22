/*


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Listnode {
	int id;
	struct Listnode *left;
	struct Listnode *right;
}listnode;



listnode* initialize(listnode *tree, int id) {          //초기화
	listnode *root;
	root = (listnode*)malloc(sizeof(listnode));

	root->id = id;
	root->left = NULL;
	root->right = NULL;

	return root;
}
listnode *addChild(int id) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->left = NULL;
	p->right = NULL;

	return p;
}

int isInternal(listnode *tree) {
	listnode *p;
	p = tree;

	if (p->left != NULL && p->right != NULL) {	// 자식 둘다 존재
		return 2;
	}
	else if (p->left != NULL && p->right == NULL) {
		return -1;  //왼쪽 자식만 존재
	}
	else if (p->left == NULL && p->right != NULL) {
		return 1;	// 오른쪽 자식만 존재
	}
	else {	//자식 X
		return 0;
	}
}

// 선위순회 순서로 노드확장 
void addNodePreorder(listnode* tree, int id, int y, int z) {
	listnode *p;
	p = tree;

	if (p->id == id) {		
		if (y != 0) {
			p->left = addChild(y);
		}
		if (z != 0) {
			p->right = addChild(z);
		}
		return;
	}
	else {
		if (isInternal(p) == 2) {
			addNodePreorder(p->left, id, y, z);
			addNodePreorder(p->right, id, y, z);
		}
		else if (isInternal(p) == -1) {
			addNodePreorder(p->left, id, y, z);
		}
		else if (isInternal(p) == 1) {
			addNodePreorder(p->right, id, y, z);
		}
	}
}
void search(listnode *tree, char str[100]) {
	listnode *p;
	p = tree;

	printf(" %d", p->id);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'R') {
			p = p->right;
		}

		else if (str[i] == 'L') {
			p = p->left;
		}
		printf(" %d", p->id);

	}

	printf("\n");

}
int main() {
	int n, x, y, z, f=0, cnt=0;
	char str[100];
	listnode *tree;
	listnode *p;
	tree = (listnode *)malloc(sizeof(listnode));	

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		
		// 처음 실행 시.
		if (f == 0) {	
			tree = initialize(tree, x);	// tree의 root
			tree->left = addChild(y);
			tree->right = addChild(z);

			f = 1;
		}		
		else {
			addNodePreorder(tree, x, y, z);
		}
		
	}

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%s", str);
		search(tree, str);
		
	}
	free(tree);
}
*/