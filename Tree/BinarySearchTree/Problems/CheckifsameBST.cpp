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


bool isSameBST(int x[],int y[], int n){

    if(n==0) return true;

    if(x[0]!=y[0]) return false;

    if(n==1) return true;

    int leftX[n-1],leftY[n-1],rightX[n-1],rightY[n-1];
    int lx=0,ly=0,rx=0,ry=0;

    for (int i = 1; i < n; i++)
    {
        if(x[i]<x[0])
            leftX[lx++]=x[i];
        else 
            rightX[rx++]=x[i];

        if(y[i]<y[0])
            leftY[ly++]=y[i];
        else
            rightY[ry++]=y[i];
    }

    if(lx!=ly) return false;
    if(rx!=ry) return false;

    return isSameBST(leftX,leftY,lx) && isSameBST(rightX,rightY,rx);
    
}

int main(){

    fastio

    int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
    int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };
 
    int n = sizeof(X) / sizeof(X[0]);
    int m = sizeof(Y) / sizeof(Y[0]);
 
    if (m == n && isSameBST(X, Y, n)) {
        printf("Given keys represent the same BSTs");
    }
    else {
        printf("Given keys represent different BSTs");
    }
 
    return 0;
    

    return 0;
}