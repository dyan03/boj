#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[100][100];
int visit[100][100];
typedef struct {
	int x, y;
}NODE;

void dfs(int sx,int sy,int N, int M){
	int x = sx;
	int y = sy;

	if (visit[x][y] == 1)return;
	else if (visit[x][y] == 0)visit[x][y] = 1;

	if (x + 1 < N && y < M && x + 1 >= 0 && y >= 0 && map[x+1][y]==1&&visit[x+1][y]==0) {

		dfs(x + 1, y,N,M);
	}
	if (x - 1 < N && y < M && x - 1 >= 0 && y >= 0 && map[x- 1][y] == 1 && visit[x- 1][y] == 0) {

		dfs(x - 1, y, N, M);
	}
	if (x < N && y + 1 < M && x >= 0 && y + 1 >= 0 && map[x][y+1] == 1 && visit[x][y+1] == 0) {

		dfs( x, y+1, N, M);
	}
	if (x < N && y - 1 < M && x >= 0 && y - 1 >= 0 && map[x ][y-1] == 1 && visit[x ][y-1] == 0) {

		dfs(x , y-1, N, M);
	}
}

void init(int N,int M) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}


int main() {

	int tc, M,N,K;
	int i, j, k;
	int x, y;
	int sx, sy;
	int cnt;

	scanf("%d", &tc);

	for (k = 0; k < tc; k++) {
		cnt = 0;
		scanf("%d %d %d", &N,&M,&K);

		init(N, M);


		for (j = 0; j < K; j++) {
			scanf("%d %d",&x,&y);
			map[x][y] = 1;
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				
				if (map[i][j] == 1 && visit[i][j] == 0) {
					
					dfs(i, j,N,M);
					cnt++;
				}
			}
		}
		
		printf("\n%d\n", cnt);
	}

}
