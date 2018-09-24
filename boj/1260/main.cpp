#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>

#define MAX_NUM 1001
using namespace std;

int map[MAX_NUM][MAX_NUM];
int visit[MAX_NUM];

void bfs(queue<int>& Que, int v,int N) {

	int cur;

	while (!Que.empty()) {

		cur=Que.front();
		Que.pop();
		printf("%d ", cur);
		visit[cur] = 1;
		for (int i = 1; i <= N; i++) {
			if (map[cur][i] == 1 && visit[i] == 0) {
				Que.push(i);
				visit[i] = 1;
			}
		}
			
	}

}

void dfs(int v, int N) {

	if (visit[v] == 1)return;
	visit[v] = 1;
	printf("%d ",v );
	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visit[i] == 0)
			dfs(i, N);
	}
}

int main() {
	
	int N, M, start;
	int i, j;
	int v1, v2;
	
	queue<int> Que;

	scanf("%d %d %d", &N, &M, &start);

	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));


	for (i = 0; i < M; i++) {

		scanf("%d %d", &v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;

	}

	dfs(start,N);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	Que.push(start);
	bfs(Que, start, N);

}

