#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define PI (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10, mod = 1e9+7;

class MaxHeap{
private:
    int* arr;
    int size;
    int capacity;
    
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i){ return 2*i+2; }


public:
    MaxHeap(int capacity){
        arr= new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    MaxHeap(int arr2[], int n){
        this->capacity = n;
        arr = new int[capacity];
        this->size = capacity;

        for (int i = 0; i < capacity; i++)
        {
            arr[i]=arr2[i];
        }
        for (int i = capacity / 2 - 1; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    int* getArr(){ return arr;}


    void insert(int key){
        if(size==capacity) return;

        size++;
        arr[size-1]=key;

        int index = size-1;

        while(index!=0 && arr[parent(index)]<arr[index]){
            swap(arr[parent(index)],arr[index]);
            index = parent(index);
        }
    }

    void increaseKey(int index, int key){
        arr[index] = key;

        int i = index;

        while(i!=0 && arr[parent(i)]< arr[i]){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }

    int extractMax(){
        if(size==0) return INT_MIN;
        if(size==1) { size--; return arr[0]; }

        
        int root = arr[0];
        swap(arr[0],arr[size-1]);
        size--;

        maxHeapify(0);
   
        return root;
    }

    void deletekey(int index){
        increaseKey(index,INT_MAX);
        extractMax();
    }

    void maxHeapify(int index){
        int l = left(index);
        int r = right(index);
        int largest = index;

        if(l<size && arr[l]>arr[largest])
            largest = l;
        
        if(r<size && arr[r]>arr[largest])
            largest = r;
        
        if(largest != index){
            swap(arr[largest],arr[index]);
            maxHeapify(largest);
        }
    }

    void buildHeap(int arr2[]){
       for (int i = 0; i < capacity; i++)
        {
            arr[i]=arr2[i];
        }
        this->size = capacity;
        for (int i = 0; i < capacity; i++)
        {
            arr[i]=arr2[i];
        }
        for (int i = capacity / 2 - 1; i >= 0; i--) {
            maxHeapify(i);
        }
        
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<'\n';
        
    }
};

void heapSort(int arr[], int n){
    MaxHeap* heap = new MaxHeap(arr,n);
    for (int i = 0; i < n; i++)
    {
        heap->extractMax();
        
    }
    int* arr2 = heap->getArr();
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
    
    
}

int main(){

    fastio

    int arr[] = {5,30,40,20,15,10};
    heapSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<'\n';
    

    return 0;
}