#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1. 
/*
int main() {
	int N, X[100], i, j, a[100], b[100], r, offset[100], imsi;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}

	scanf("%d", &r);			 // r�� reverse. ������ ������ ����
	for (i = 0; i <r; i++) {
		scanf("%d %d", &a[i], &b[i]);
		offset[i] = b[i] - a[i];
	}

	i = 0;
	while (i < r) {
		for (j = a[i]; j <= offset[i] / 2 + a[i]; j++) {
			imsi = X[j];
			X[j] = X[a[i] + b[i] - j];
			X[a[i] + b[i] - j] = imsi;
		}	
		i++;
	}
	for (i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}
}
*/

// 2.
/*
int main() {
	int N, X[100], A, s[99], i, movefrom, moveto;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &A);	//A�� �����ٲ� ������ ����
	for (i = 0; i < A; i++) {
		scanf("%d", &s[i]);  // s�� switch. ���� �ٲ� ����
	}

	movefrom = X[s[0]];				// move from s[0] : s[0] ��ġ�κ���
	for (i = 0; i < A; i++) {
		moveto = movefrom;
		movefrom = X[s[i]];
		X[s[i]] = moveto;			// move to s[i] : s[i]��ġ�� �̵��ض�.
	}
	for (i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}

}
*/


//3.
/*
int main() {
	int N, X[100][100], i, j, k = 0, f = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i % 2 == 0) {		// ���� Ȧ��
				X[i][j] = ++k;		//++k;
			}
			else {
				if (f == 0) {
					k = N * (i + 1);	//i+1
					f = 1;
				}
				X[i][j] = k--;		//k--;
			}	
		}
		f = 0;
		k = N * (i + 1);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", X[i][j]);
		}
		printf("\n");
	}
}
*/


//4. 
/*
int main()
{
	int X[100][100];
	int N, M;
	int imax, jmax;
	int i, j;
	int a = 0, b = -1, turn = 1;
	int num = 1;
	int max= 0;

	scanf("%d %d", &N, &M);

	max = N * M;
	imax = N;
	jmax = M;

	while (num != max + 1)		//num<=max
	{
		for (i = 1; i <= jmax; i++)
		{
			b += turn;
			X[a][b] = num;
			num++;
		}
		imax--;
		for (i = 1; i <= imax; i++)
		{
			a += turn;
			X[a][b] = num;
			num++;
		}
		turn *= -1;
		jmax--;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf(" %d ", X[i][j]);
		}
		printf("\n");
	}
}
*/




//5.
/*
int main() {
	int N, M, X[100][100], i, j;
	scanf("%d %d", &N, &M);

	// ����: ������ ���� ���ؼ��� X[i - 1][j + 1] �� �������� ����.
	// i-1���� ��� ����� �Է� �Ǿ�� ���� ����� �Է°���!!!
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0) {		// X[0][0] = 1;
				X[i][j] = 1;
			}
			else if (i == 0) {			// 0�࿡ ���� ���� �Է�
				if (N <= j) {		// M>N�� ���
					X[i][j] = X[i][j - 1] + N;
				}
				else {
					X[i][j] = X[i][j - 1] + j;
				}
			}
			else if (i != 0 && j == M - 1) {		// && i != 0 
				//X[i][j] = X[i - 1][j] + - i;
				if (N-M >= i) {						// N>M �� ���
					X[i][j] = X[i - 1][j] + M;
				}
				else {
					X[i][j] = X[i - 1][j] + N + 1 - i;
				}
			}
			else {									// �밢������ �����ֱ�
				X[i][j] = X[i - 1][j + 1] + 1;
			}	
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", X[i][j]);
		}
		printf("\n");
	}
}
*/

// ù��° else if������ N>M�� ��찡 ���� ex) 4*6���
// �̸� ���� if�����

// �ι�° else if���� ����ϴ� ������ ����
// ������ ���� ���ؼ��� X[i - 1][j + 1] �� �������� ����.
// i-1�� ��� ����� �ԷµǾ�߸� �ϹǷ� �ؿ� else���� �̿��� �밢������ ������ �� ����.
// �׷��� �ι�° else if���� �ʿ��ϴ�.
// �밢������ ��ĭ�� �������İ� �߿�.
