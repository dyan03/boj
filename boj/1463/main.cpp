#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 1000001

using namespace std;

int memoi[MAX_N];

int dp(int n){
    int f[3]={MAX_N,MAX_N,MAX_N};
    int min,i;


    if(n==3)return 1;
    if(n==2)return 1;
    if(n==1)return 0;
    if(n==0)return 0;

    if(memoi[n]!=0)return memoi[n];

    if(n%2==0){
    f[0]=dp(n/2)+1;
    }

    if(n%3==0){
    f[1]=dp(n/3)+1;
    }
    f[2]=dp(n-1)+1;

    min=f[0];
    for(i=0;i<3;i++){

        min=min>f[i]?f[i]:min;
    }

    return memoi[n]=min;
}


int main(){

int N;
//freopen("input.txt","r",stdin);
scanf("%d",&N);

printf("%d",dp(N));

}
