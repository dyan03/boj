#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX_NUM 50

int comp1(int a, int b) {
	return a < b;
}
int comp2(int a, int b) {
	return a > b;
}


int main() {

	int N;
	int A[MAX_NUM];
	int B[MAX_NUM];

	int i, j;
	int sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	sort(A, A + N, comp1);
	sort(B, B + N, comp2);

	for (i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	printf("%d", sum);
	
}
