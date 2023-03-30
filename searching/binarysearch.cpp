#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int lowerbound(int arr[],int target,int n){//returns index of lower bound
    int lo=0,hi=n-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(arr[mid]<target){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(arr[lo]>=target){
        return lo;
    }
    else if(arr[hi]>=target){
        return hi;
    }
    else return -1;//not found
}

int upperbound(int arr[],int target,int n){//returns index of lower bound
    int lo=0,hi=n-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(arr[mid]<=target){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(arr[lo]>target){
        return lo;
    }
    else if(arr[hi]>target){
        return hi;
    }
    else return -1;//not found
}

void binarysearch(int arr[],int target,int n){//prints index of target or not found
    int lo=0,hi=n-1;
    int mid,flag=0;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]==target){
            flag=1;
            cout<<mid<<endl;
            break;
        }
        if(arr[mid]<target){
            lo=mid+1;
        }
        else hi=mid-1;
    }
    if(flag==0)cout<<"Not found\n";

}

int main(){
    fastio

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    //if not sorted
    sort(arr,arr+n);

    //binarysearch(arr,target,n);
    int a=upperbound(arr,target,n);
    cout<<a<<endl;

    return 0;
}
//logn

