#include <iostream>
#include <cstdio>
#include <algorithm>


#define MAX_N 301

using namespace std;
int arr[MAX_N];
int memoi[MAX_N];


int dp(int n){


    if(n==0)return arr[0];
    else if(n==1)return arr[1]+arr[0];
    else if(n==2)return max(arr[2]+arr[0],arr[2]+arr[1]);

    if(memoi[n]!=0)return memoi[n];
    return memoi[n]=max(arr[n]+arr[n-1]+dp(n-3),arr[n]+dp(n-2));

}



int main(){


int N,i,j;

freopen("input.txt","r",stdin);


scanf("%d",&N);

for(i=0;i<N;i++){
    scanf("%d",&arr[i]);

}


printf("%d",dp(N-1));

return 0;
}
