#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int comp(const int& a, const int& b) {
	return a >= b;
}

void mysort(int * arr, int size) {
	int tmp, i, j;
	
	for (i = 1; i < size-1; i++) {
		for (j = i + 1; j <size; j++) {
			if (arr[i] <= arr[j]) {

				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	int N, S, P;
	int i, j;
	int* rank;
	int rank_num;
	int rank_point;
	int chk = 1;
	int res;
	scanf("%d %d %d", &N, &S, &P);
	rank = new int[P + 2];
	memset(rank, 0, sizeof(int)*(P + 2));
	
	for (i = 1; i <= N; i++) {
		scanf("%d", &rank[i]);
	}
	rank[N + 1] = S;

	mysort(rank, N + 2);
	
	for (i = 1; i <= N + 1; i++) {
		if (chk==1&&rank[i] == S) {
			rank_num = i;
			rank_point = i;
			chk = 2;
		}
		else if (chk == 2 && rank[i] == S) {
			if (i==(P+1))rank_point = i;
		}
	}
	if (rank_point <= P)res = rank_num;
	else res = -1;
	printf("%d", res);
}


