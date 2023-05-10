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

int arr[N];

int fibb(int n){
    if(n<=1) return n;
    if(arr[n]!=-1) return arr[n];

    return arr[n] = fibb(n-1)+fibb(n-2);
}

int main(){

    fastio
    memset(arr,-1,sizeof arr);
    for (int i = 0; i < 6; i++)
    {
        cout<<fibb(i)<<" ";
    }cout<<'\n';
    

    return 0;
}