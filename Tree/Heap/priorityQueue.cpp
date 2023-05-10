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

class priorityQueue{
private:
    int* arr;
    int size;
    int capacity;

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }

    void maxHeapify(int index){
        int l = left(index);
        int r = right(index);
        int largest = index;

        if(l<size && arr[l]>arr[index])
            largest = l;
        
        if(r<size && arr[r]>arr[index])
            largest = r;
        
        if(largest != index){
            swap(arr[largest],arr[index]);
            maxHeapify(largest);
        }
    }

public:
    priorityQueue(int capacity){
        arr = new int[capacity];
        size= 0;
        this->capacity = capacity;
    }

    void push(int value){
        if(size==capacity) return;

        size++;
        arr[size-1] = value;

        int i = size-1;

        while(i!=0 && arr[parent(i)]< arr[i]){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }

    int pop(){
        if(size==0) return INT_MIN;
        if(size==1) { size--; return arr[0]; }
        int root = arr[0];
        arr[0]= arr[size-1];

        size--;

        maxHeapify(0);

        return root;

    }
};

int main(){

    fastio

    priorityQueue q = priorityQueue(10);
    q.push(1);
    q.push(5);

    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";

    return 0;
}