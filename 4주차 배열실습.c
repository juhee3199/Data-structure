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

	scanf("%d", &r);			 // r은 reverse. 뒤집기 정보의 개수
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
	scanf("%d", &A);	//A는 순서바꿈 정보의 길이
	for (i = 0; i < A; i++) {
		scanf("%d", &s[i]);  // s는 switch. 순서 바꿈 정보
	}

	movefrom = X[s[0]];				// move from s[0] : s[0] 위치로부터
	for (i = 0; i < A; i++) {
		moveto = movefrom;
		movefrom = X[s[i]];
		X[s[i]] = moveto;			// move to s[i] : s[i]위치로 이동해라.
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
			if (i % 2 == 0) {		// 행이 홀수
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

	// 주의: 마지막 열에 대해서는 X[i - 1][j + 1] 이 존재하지 않음.
	// i-1행의 모든 행렬이 입력 되어야 다음 행렬이 입력가능!!!
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0) {		// X[0][0] = 1;
				X[i][j] = 1;
			}
			else if (i == 0) {			// 0행에 대해 먼저 입력
				if (N <= j) {		// M>N일 경우
					X[i][j] = X[i][j - 1] + N;
				}
				else {
					X[i][j] = X[i][j - 1] + j;
				}
			}
			else if (i != 0 && j == M - 1) {		// && i != 0 
				//X[i][j] = X[i - 1][j] + - i;
				if (N-M >= i) {						// N>M 일 경우
					X[i][j] = X[i - 1][j] + M;
				}
				else {
					X[i][j] = X[i - 1][j] + N + 1 - i;
				}
			}
			else {									// 대각선으로 더해주기
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

// 첫번째 else if문에서 N>M일 경우가 존재 ex) 4*6행렬
// 이를 위해 if문사용

// 두번째 else if문을 사용하는 이유와 원리
// 마지막 열에 대해서는 X[i - 1][j + 1] 이 존재하지 않음.
// i-1의 모든 행렬이 입력되어야만 하므로 밑에 else문을 이용해 대각선으로 더해줄 수 없음.
// 그래서 두번째 else if문이 필요하다.
// 대각선으로 몇칸을 지나느냐가 중요.
