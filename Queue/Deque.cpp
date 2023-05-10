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

class CircularDeque{
private:
    int* arr;
    int capacity;
    int size;
    int front;
    int rear;

public:

    CircularDeque(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        this->size=0;
        front = rear = -1;
    }

    void insertFront(int value){
        if(front==-1 && rear==-1){
            front = rear = 0;
            arr[front] = value;
            this->size++;
            return;
        }

        else if((front+capacity-1)%capacity==rear) return;
        
        front = (front+capacity-1)%capacity;
        arr[front] = value;
        this->size++;
    }


    void insertBack(int value){
         if(front==-1 && rear==-1){
            front = rear = 0;
            arr[rear] = value;
            this->size++;
            return;
        }

        else if((rear+1)%capacity==front) return;
        
        rear = (rear+1)%capacity;
        arr[rear] = value;
        this->size++;
    }

    int removeFront(){
        if(front==-1) return INT_MIN;

        if(front==rear){
            front = rear = -1;
            int val =arr[front];    
            this->size--;
            return val;
        }

        int val =arr[front];
        front = (front+1)%capacity;
        this->size--;
        return val;
    }

    int removeBack(){
        if(rear==-1) return INT_MIN;

        if(front==rear){
            front = rear = -1;
            int val =arr[rear];    
            this->size--;
            return val;
        }

        int val =arr[rear];
        rear = (rear+capacity-1)%capacity;
        this->size--;
        return val;
    }

    int peekFront(){
        if(front==-1) return INT_MIN;
        return arr[front];
    }

    int peekBack(){
        if(rear==-1) return INT_MIN;
        return arr[front];
    }

    bool isEmpty(){
        if(front==rear && rear==-1) return true;
        return false;
    }

    bool isFull(){
        if((front+1)%capacity==rear) return true;
        return false;
    }


    void print(){
        int i = front;

        while (i!=rear)
        {
            cout<<arr[i]<<"->";
            i=(i+1)%capacity;
        }
        cout<<arr[i]<<'\n';
    }
    

};

int main(){

    fastio

    CircularDeque q = CircularDeque(5);
    q.insertFront(1);
    q.print();
    q.insertBack(2);
    q.print();
    q.insertFront(3);
    q.print();

    return 0;
}