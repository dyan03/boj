#include <iostream>
#include <cstdio>
#include <queue>

#define MAX_N 101

using namespace std;

typedef struct{

    int x;
    int y;
    int z;
}NODE;

int map[MAX_N][MAX_N][MAX_N];
int visit[MAX_N][MAX_N][MAX_N];
int MAX_DAY;

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};

int check(int x,int y,int z,int M, int N, int H){

    if(x>=0&&y>=0&&z>=0&&x<M&&y<N&&z<H)return 1;
    else return 0;

}

void bfs(queue<NODE>& q,int M,int N,int H){
    int i;
    int x,y,z,px,py,pz;

    while(!q.empty()){


        NODE n=q.front();
        q.pop();

        x=n.x;
        y=n.y;
        z=n.z;

        for(i=0;i<6;i++){

            px=x+dx[i];
            py=y+dy[i];
            pz=z+dz[i];

            if(check(px,py,pz,M,N,H)&&visit[pz][py][px]==0&&map[pz][py][px]!=-1){

                visit[pz][py][px]=visit[z][y][x]+1;
                MAX_DAY=MAX_DAY<visit[pz][py][px]?visit[pz][py][px]:MAX_DAY;

                NODE n_={px,py,pz};
                q.push(n_);
            }
        }
    }

}


int main(){

int M,N,H;
int i,j,k;

freopen("input.txt","r",stdin);


scanf("%d %d %d",&M,&N,&H);
queue<NODE>q;

for(k=0;k<H;k++){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){

            scanf("%d",&map[k][i][j]);
        }

    }
}


for(k=0;k<H;k++){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(map[k][i][j]==1){
                NODE n={j,i,k};
                visit[k][i][j]=1;
                q.push(n);
            }

        }

    }
}
MAX_DAY=1;


bfs(q,M,N,H);

for(k=0;k<H;k++){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(visit[k][i][j]==0&&map[k][i][j]!=-1){

                printf("%d",-1);
                return 0;
            }

        }

    }
}



printf("%d",MAX_DAY-1);

return 0;
}
