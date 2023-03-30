#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
double eps=1e-6;//accuracy upto 5 decimal places

double multiply(double mid,int n){
    double ans=1;
    for(int i=0;i<n;i++){
        ans*=mid;
    }
    return ans;
}

int main(){
    //fastio

    double x;
    cin>>x;//the number whose root we want to find

    int n;
    cin>>n;

    double lo=1,hi=x,mid;
    while(hi-lo>eps){//basically lo and hi equal upto 5 decimal places
        mid=(lo+hi)/2;
        //for nth root
        if(multiply(mid,n)<x){
        //for sq root
        //if(mid*mid<x){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout<<setprecision(6)<<lo<<endl;

    return 0;
}

//p*log(n(10^d))

