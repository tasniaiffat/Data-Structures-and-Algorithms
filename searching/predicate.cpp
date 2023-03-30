#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
double eps=1e-6;//accuracy upto 5 decimal places
const int N=1e6+10;
int n;
long long m;
long long trees[N];

//this generates a predicate function
bool isWood(int h){
    long long wood=0;
    for(int i=0;i<n;i++){
        if(trees[i]>=h){
            wood+=(trees[i]-h);
        }
    }
    return (wood>=m);
}

int main(){
    //fastio

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>trees[i];
    }
    long long lo=0,hi=1e9,mid;
    while(hi-lo>1){
        mid=(lo+hi)/2;
        if(isWood(mid)){
            lo=mid;
        }
        else{
            hi=mid-1;
        }
    }
    if(isWood(hi)){
        cout<<hi<<endl;
    }
    else if(isWood(lo)){
        cout<<lo<<endl;
    }
    //else cout<<-1<<endl;

    return 0;
}
//O(NlogH)

