#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1.
/*
int modulo(int a, int b) {
	while (a >= b) {
		a -= b;
	}
	return a;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

	return 0;
}
*/
/*
int modulo(int a, int b) {
	while (a >= b) {
		a -= b;
		if (a < b) {
			return a;
		}
	}
}
*/

//2.  
// 2차원 배열 매개변수 사용하기
//https://dojang.io/mod/page/view.php?id=563
/*
int mostOnes(int A[][100], int n) {
	int i = 0, j = 0, row = 0;

	while ((i < n)&(j < n)) {
		if (A[i][j] == 0) {
			i += 1;
		}
		else {
			row = i;
			j += 1;
		}
	}
	return row;
}
int main() {
	int n, A[100][100], i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("%d", mostOnes(A, n));
}
*/

// 3.
// 3-1.
/*
#include <stdlib.h>

int* prefixAverages1(int *X, int n){
	int i, j;
	float sum;
	int *A = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {		
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		sum /=(i + 1);
		sum += 0.5;
		sum /= 1;
		A[i] = sum;
	}
	return A;
}
int* prefixAverages2(int *X, int n) {
	int i;
	float sum = 0;
	int *A = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (sum / (i + 1) + 0.5) / 1;
	}
	return A;
}
int main() {
	int n, i;
	int *X, *A;

	scanf("%d", &n);
	X = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &X[i]);
	}
	
	A = prefixAverages1(X, n);
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	A = prefixAverages2(X, n);
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	
	free(X);
	free(A);
}
*/


// 3-2.
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

# include <stdlib.h>
# include <time.h>
# include <Windows.h>

int* prefixAverages1(int *X, int n) {
	int i, j;
	float sum;
	int *A;
	A = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (sum / (i + 1) + 0.5) / 1;
	}
	return A;
}
int* prefixAverages2(int *X, int n) {
	int i;
	float sum = 0;
	int *A = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (sum / (i + 1) + 0.5) / 1;
	}
	return A;
}
int main() {
	int n, i;
	int *X, *A;

	scanf("%d", &n);
	X = (int *)malloc(sizeof(int)*n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		X[i] = (rand() % 10000 + 1);
	}

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	A = prefixAverages1(X, n);
	QueryPerformanceCounter(&end);

	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.9f ms\n", ((double)diff.QuadPart / ((double)ticksPerSec.QuadPart / 1000)));

	// prefixAverages2
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	// 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
	A = prefixAverages2(X, n);
	QueryPerformanceCounter(&end);

	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.9f ms\n", ((double)diff.QuadPart / ((double)ticksPerSec.QuadPart / 1000)));

	free(X);
	free(A);
}
*/
