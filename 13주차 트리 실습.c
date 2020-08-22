//1. 

// addLChild 랑 addRchild 동일.. addChild로 변경해서 사용하기


/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Listnode {
	int id;
	int data;
	struct Listnode *left;
	struct Listnode *right;
}listnode;

listnode* initialize(listnode *tree) {          //초기화
	listnode *root;
	root = (listnode*)malloc(sizeof(listnode));

	root->id = 0;
	root->data = NULL;
	root->left = NULL;
	root->right = NULL;

	return root;
}
listnode* addLChild(int id, int data) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;		
}
listnode* addRChild(int id, int data) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;		
}
// 두개의 자식노드와 연결.
listnode* addParent(int id, int data, listnode *left, listnode *right) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = left;
	p->right = right;

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
void preOrder(listnode *tree) {
	listnode *p;
	p = tree;

	if (p == NULL) {
		return;
	}

	printf(" %d", p->data);
	preOrder(p->left);
	preOrder(p->right);
}
void inOrder(listnode *tree) {
	listnode *p;
	p = tree;
	if (p == NULL) {
		return;
	}

	inOrder(p->left);
	printf(" %d", p->data);
	inOrder(p->right);
}
void postOrder(listnode *tree) {
	listnode *p;
	p = tree;
	if (p == NULL) {
		return;
	}

	postOrder(p->left);
	postOrder(p->right);
	printf(" %d", p->data);
}
void idOrder(listnode* tree, int cmd, int id) {
	listnode *p;
	p = tree;

	if (p->id == id) {
		if (cmd == 1) {
			preOrder(tree);
		}
		else if (cmd == 2) {
			inOrder(tree);
		}
		else if (cmd == 3) {
			postOrder(tree);
		}
	}
	else {
		if (isInternal(p) == 2) {
			idOrder(p->left, cmd, id);
			idOrder(p->right, cmd, id);
		}
		else if (isInternal(p) == -1) {
			idOrder(p->left, cmd, id);
		}
		else if (isInternal(p) == 1) {
			idOrder(p->right, cmd, id);
		}
	}
}
int main() {
	int cmd, id;
	listnode *tree, *left, *right, *parent;  
	tree = (listnode *)malloc(sizeof(listnode));

	tree = initialize(tree);	// tree의 root

	right = addRChild(8,80);
	left = addLChild(7,130);
	parent = addParent(6, 120,left, right);
	tree->right = parent;						//6

	right = addRChild(5, 90);
	left = addLChild(4,70);
	parent = addParent(2, 30, left, right);
	tree->left = parent;

	parent = addParent(3, 50, NULL, tree->right); //tree->right =6
	tree->right = parent;

	parent = addParent(1, 20, tree->left, tree->right);	//right=3
	tree = parent;

	
	scanf("%d %d", &cmd, &id);
	if (id > 8 || id < 1) {
		printf("%d\n", -1);
		return -1;
	}

	idOrder(tree, cmd, id);

	free(tree);
}
*/

/*
listnode *p;
p = tree;
while (isInternal(p) != 0) {
	printf("%d %d\n", p->id, p->data);
	p = p->left;
}
printf("%d %d\n", p->id, p->data);
*/



// 2.

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Listnode {
	int id;
	int data;
	struct Listnode *left;
	struct Listnode *right;
}listnode;

listnode* initialize(listnode *tree) {          //초기화
	listnode *root;
	root = (listnode*)malloc(sizeof(listnode));

	root->id = 0;
	root->data = NULL;
	root->left = NULL;
	root->right = NULL;

	return root;
}
listnode* addLChild(int id, int data) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;
}
listnode* addRChild(int id, int data) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;
}
// 두개의 자식노드와 연결.
listnode* addParent(int id, int data, listnode *left, listnode *right) {
	listnode *p;
	p = (listnode *)malloc(sizeof(listnode));

	p->id = id;
	p->data = data;
	p->left = left;
	p->right = right;

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
int preOrder(listnode *tree) {
	listnode *p;
	p = tree;

	if (p == NULL) {
		return 0;
	}

	return p->data + preOrder(p->left) + preOrder(p->right);
}

void idOrder(listnode* tree, int id) {
	int sum = 0;

	listnode *p;
	p = tree;

	if (p->id == id) {
		sum = preOrder(tree);
		printf("%d", sum);
	}
	else {
		if (isInternal(p) == 2) {
			idOrder(p->left, id);
			idOrder(p->right, id);
		}
		else if (isInternal(p) == -1) {
			idOrder(p->left, id);
		}
		else if (isInternal(p) == 1) {
			idOrder(p->right, id);
		}
	}
}
int main() {
	int id, *sum = 0;
	listnode *tree, *left, *right, *parent;
	tree = (listnode *)malloc(sizeof(listnode));

	tree = initialize(tree);	// tree의 root

	right = addRChild(8, 80);
	left = addLChild(7, 130);
	parent = addParent(6, 120, left, right);
	tree->right = parent;						//6

	right = addRChild(5, 90);
	left = addLChild(4, 70);
	parent = addParent(2, 30, left, right);
	tree->left = parent;

	parent = addParent(3, 50, NULL, tree->right); //tree->right =6
	tree->right = parent;

	parent = addParent(1, 20, tree->left, tree->right);	//right=3
	tree = parent;


	scanf("%d", &id);
	if (id > 8 || id < 1) {
		printf("%d\n", -1);
		return -1;
	}

	idOrder(tree, id);

	free(tree);
}

*/