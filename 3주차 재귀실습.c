#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//1.
/*
int sum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + sum(n - 1);
	}
}
int main()
{
	int n;
	int result = 0;
	scanf("%d", &n);
	result = sum(n);
	printf("%d",result);
	
}
*/

//2.
/*
void digits(int n) {
	if(n<10){
		printf("%d\n", n);
	}
	else { 
		digits(n/10);
		printf("%d\n", n%10);
	}
}
int main() {
	int n, i = 0;
	scanf("%d", &n);
	if (n < 10) {
		printf("%d", n);
	}
	else {
		digits(n);
	}
}
*/
 

//3.
/*
void digits(int n) {
	if (n < 10) {
		printf("%d", n);
	}
	else {
		printf("%d\n", n % 10);
		digits(n / 10);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 10) {
		printf("%d", n);
	}
	else {
		digits(n);
	}
}
*/



//4.
/*
int arrmax(int n, int a[]) {
	int m;
	if (n == 1) {
		return a[0];
	}	
	
	m = arrmax(n - 1, a);
	if (m > a[n-1]) {
		return m;
	}
	else{
		return a[n-1];
	}
}
int main() {
	int N, a[20], i, max;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	if (N == 1) {
		printf("%d", a[0]);
	}
	else {
		max = arrmax(N, a);
		printf("%d",max);
	}	
}
*/

//5.
/*
void rhanoi(int N,char from, char aux, char to) {
	if (N == 1) {
		printf("%c %c\n", from,to);
		return;
	}
	rhanoi(N - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rhanoi(N - 1, aux, from, to);
	return;
}
int main() {
	int N;
	char from, aux, to;
	from = 'A', aux = 'B', to = 'C';
	
	scanf("%d", &N);
	rhanoi(N, from, aux, to);
}
*/

//6.
/*
int gcd(int a, int b) {
	int r;
	if (b==0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}
int main() {
	int a, b, m;
	scanf("%d %d", &a, &b);
	if (a < b) {
		m=gcd(b, a);
	}
	else {
		m=gcd(a, b);
	}
	printf("%d", m);
}
*/

// 7.
/*
#include <string.h>
int find(char str[], char s, int n) {
	int cnt = 0;
	if (n == 1) {
		if (str[0] == s) {
			cnt += 1;
		}
		return cnt;
	}
	cnt = find(str, s, n - 1);

	if (str[n-1] == s) {
		cnt += 1;
	}
	return cnt;
}
int main() {
	char str[100];
	char s;
	int len, count;

	scanf("%s", str);
	scanf(" %c", &s);
	len=strlen(str);
	
	count = find(str, s, len);
	printf("%d", count); 

}
*/