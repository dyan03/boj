#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;


typedef struct{
    int a,b;
}ROOM;

bool operator <(ROOM A, ROOM B){

    return A.a<B.a;
}


int main(){

priority_queue<ROOM> pq;

ROOM r1,r2,r3;
r1={1,2};
r2={5,3};
r3={2,0};

pq.push(r1);
pq.push(r2);
pq.push(r3);

while(!pq.empty()){
printf("%d ",pq.top().a);
pq.pop();
}
}
