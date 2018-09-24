#include <iostream>
#include <cstdio>

#define MAX_N 15

using namespace std;

int map[MAX_N][MAX_N];
int N,len;


int checker(int r, int c){

    int i,j;

    for(i=0;i<N;i++){

        if(map[r][i]==1||map[i][c]==1)return 0;
    }

    for(i=r,j=c;i<N&&j<N;i++,j++){

        if(map[i][j]==1)return 0;
    }

    for(i=r,j=c;i>=0&&j>=0;i--,j--){

        if(map[i][j]==1)return 0;
    }

    for(i=r,j=c;i>=0&&j<N;i--,j++){

        if(map[i][j]==1)return 0;
    }

    for(i=r,j=c;i<N&&j>=0;i++,j--){

        if(map[i][j]==1)return 0;
    }


    return 1;
}


int checker_(int r, int c){

    int i,j;

    for(i=0;i<N;i++){

        map[r][i]=1;
        map[i][c]=1;
    }

    for(i=r,j=c;i<N&&j<N;i++,j++){

        map[i][j]=1;
    }

    for(i=r,j=c;i>=0&&j>=0;i--,j--){

        map[i][j]=1;
    }

    return 1;
}

void bt(int N,int n){


     int i,j;

     if(n==N){

     len++;
     return;
     }


     for(i=0;i<N;i++){
        if(checker(n,i)){
            map[n][i]=1;
            bt(N,n+1);
            map[n][i]=0;
        }


     }

}




int main(){

    int i,j;

    freopen("input.txt","r",stdin);
    scanf("%d",&N);

    bt(N,0);


    printf("%d",len);


return 0;
}
