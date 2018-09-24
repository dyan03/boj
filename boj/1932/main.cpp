#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 501

using namespace std;

int arr[MAX_N][MAX_N];
int memoi[MAX_N][MAX_N];


int dp(int r,int c){


    if(r==0){

        return memoi[r][c]=arr[r][c];
    }

    if(memoi[r][c]==0)return memoi[r][c]=max(arr[r][c]+dp(r-1,c),arr[r][c]+dp(r-1,c+1));
    else return memoi[r][c];


}


int main(){

int N,i,j;

freopen("input.txt","r",stdin);



scanf("%d",&N);

for(i=0;i<N;i++){

    for(j=0;j<=i;j++){
    scanf("%d",&arr[N-i-1][j]);
    }
}




printf("%d",dp(N-1,0));

return 0;
}
