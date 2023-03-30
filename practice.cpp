#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    
    int arr[]={2,7,1,10,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
        

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;;
    return 0;
}