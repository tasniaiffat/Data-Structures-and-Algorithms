#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;
int i=1;

void Hanoi(int n,int source, int inter, int dest){
    if(n==1){
        cout<<i<<". Move bead "<<n<<" from pole "<<source<<" to pole "<<dest<<"\n";
        i++;
        return;
    }

    Hanoi(n-1,source,dest,inter);
    cout<<i<<". Move bead "<<n<<" from pole "<<source<<" to pole "<<dest<<"\n";
    i++;
    Hanoi(n-1,inter,source,dest);
}

void move(int n, int source, int inter, int dest, stack<int> pole[]){
    if(n==1){
        pole[dest].push(pole[source].top());
        pole[source].pop();
        return;
    }

    move(n-1,source,dest,inter,pole);
    pole[dest].push(pole[source].top());
    pole[source].pop();
    move(n-1,inter,source,dest,pole);
}

void HanoiUsingStacks(int n, int source, int inter, int dest){
    stack<int> pole[4];

    for (int i = n; i > 0; i--)
    {
        pole[source].push(i);
    }
    

    move(n,source,inter,dest,pole);

    while(!pole[dest].empty()){
        cout<<pole[dest].top()<<" ";
        pole[dest].pop();
    }cout<<'\n';
    
}

int main(){

    fastio

    HanoiUsingStacks(3,1,2,3);

    return 0;
}