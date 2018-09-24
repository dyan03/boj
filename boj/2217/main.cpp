#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int arr[MAX_N];

int comp( const int&a,const int& b){

    return a>b;
}


int main(){

int N,i,j;
int result,result_;
freopen("input.txt","r",stdin);

scanf("%d",&N);

for(i=0;i<N;i++){

    scanf("%d",&arr[i]);
}

sort(arr,arr+N,comp);

result=arr[0];
for(i=0;i<N;i++){

result=result<arr[i]*(i+1)?arr[i]*(i+1):result;

}

printf("%d",result);
}
