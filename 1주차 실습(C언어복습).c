#include <stdio.h>

/*
int main()
{
	printf("첫번째 프로그램입니다.");
	return 0;
}
*/

// 예시
/*
int main()
{
	int n = 0, sum = 0;
	while (1) {
		n++;
		sum += n;
		if (sum > 100) break;
	}
	printf("%d\n", n);
	printf("%d", sum);
}
*/

// 1.
/*
int sum(int n) 
{
	int i, sum=0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main()
{
	int X, i, total=0;
	scanf("%d", &X);

	for (i = 1; i <= X; i++) {
		total+=sum(i);
	}
	printf("%d", total);
}
*/

// 2.		////
/*
void ABC(int arr[],int k)
{
	int i, imsi, max = arr[k], m = k;
	for (i = k; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
			m = i;
		}
	}
	imsi = arr[m];
	arr[m] = arr[k];
	arr[k] = imsi;
}

int main()
{
	int arr[10], i, k = 0;	
	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	while (k < 9) {
		ABC(arr, k);
		k++;
	}

	for (i = 0; i < 10; i++) {
		printf(" %d", arr[i]);
	}
}
*/

// 3.	//<고급 C프로그래밍 및 실습> 9장 포인터 실습 문제
/*
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int N, arr[50], a, b, i;
	int *p = arr;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", p++);
	}
	scanf("%d %d", &a, &b);
	
	p = arr; //p의 값 arr[0]의 값으로 초기화
	swap(p+a, p+b);

	for (i = 0; i < N; i++) {
		printf(" %d", *p++);
	}
}
*/

// 4.	
// 자기주도 C프로그래밍 CH 14. 문자열1 Q.9
/*
#include <string.h>
int main()
{
	int i, j, len;
	char str[100], imsi;

	scanf("%s", str);
	len = strlen(str);

	printf("%s \n", str);
	
	for (i = 1; i < len; i++) {
		imsi = str[0];
		for (j = 0; j < len - 1; j++) {
			str[j] = str[j + 1];
		}
		str[len - 1] = imsi;
		printf("%s \n", str);
	}

}
*/

// 5.
/*
struct time
{
	int h, m, s;
};
int main()
{
	struct time a, b, sub;
	scanf("%d %d %d", &a.h, &a.m, &a.s);
	scanf("%d %d %d", &b.h, &b.m, &b.s);

	if (b.s < a.s) {
		sub.s = (b.s + 60) - a.s;
		b.m -= 1;
	}
	else {
		sub.s = b.s - a.s;
	}

	if (b.m < a.m) {
		sub.m = (b.m + 60) - a.m;
		b.h -= 1;
	}
	else {
		sub.m = b.m - a.m;
	}

	sub.h = b.h - a.h;

	printf("%d %d %d", sub.h, sub.m, sub.s);
}
*/

//6.
/*
struct student {
	char name[9];
	int score;
};
int main()
{
	struct student s[5];
	int i, sum = 0, avg = 1;

	for (i = 0; i < 5; i++) {
		scanf("%s %d", s[i].name, &s[i].score);
		sum += s[i].score;
	}
	avg = sum / 5;

	for (i = 0; i < 5; i++) {
		if (s[i].score <= avg) {
			printf("%s\n", s[i].name);
		}
	}
}
*/

// 7.
// https://modoocode.com/98
/*
#include <stdlib.h>

int main()
{
	int N, i, j;
	int *arr, *arr2;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	arr2= (int *)malloc(sizeof(int)*N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr2[i]);
	}

	j = N-1;
	for (i = 0; i < N; i++) {
		printf(" %d", arr[i] + arr2[j]);
		j--;
	}
	free(arr);
	free(arr2);
}
*/


/*
// 8.
// https://modoocode.com/100

#include <stdlib.h>
struct student {
	char name[7];
	int kor, eng, mat;
};
int main()
{
	struct student *arr;
	int N, i, *sum=0;
	float *avg;

	scanf("%d", &N);
	arr = (struct student *)malloc(sizeof(struct student)*N);
	sum	= (int *)malloc(sizeof(int)*N);
	avg = (float *)malloc(sizeof(float)*N);
	
	for (i = 0; i < N; i++) {
		scanf("%s %d %d %d", arr[i].name, &arr[i].kor, &arr[i].eng, &arr[i].mat); //
		sum[i] = arr[i].kor + arr[i].eng + arr[i].mat;
		avg[i] = sum[i] / 3.0;	//
	}
	for (i = 0; i < N; i++) {
		printf("%s %.1f", arr[i].name, avg[i]);
		if (arr[i].kor >= 90 || arr[i].eng >= 90 || arr[i].mat >= 90) {
			printf(" GREAT");
		}
		if (arr[i].kor < 70 || arr[i].eng < 70 || arr[i].mat < 70) {
			printf(" BAD");
		}
		printf("\n");
	}

	free(arr);
	free(sum);
	free(avg);
}
*/


