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

class Queue{
private:
    int* arr;
    int capacity;
    int size;
    int front, rear;

public:
    Queue(int capacity){
        arr = new int[capacity];
        front = rear = -1;
        this->capacity = capacity;
        this->size=0;
    }

    int get_size(){
        return this->size;
    }

    void enqueue(int value){
        if(front==-1 && rear==-1){
            front = rear = 0;
            arr[rear]=value;
        }

        else if((rear+1)%capacity==front)return;
        else{
            rear = (rear+1)%capacity;
            arr[rear] = value;
        }
        
        size++;
    }

    void dequeue(){
        if(front==-1) return;
        if(front==rear){
            front=rear=-1;
        }
        else{
            front = (front+1)%capacity;
        }
        this->size--;
    }

    int peek(){
        return arr[front];
    }

    bool isEmpty(){
        if(front==-1 && rear==-1) return true;
        return false;
    }

    bool isFull(){
        if((rear+1)%capacity==front) return true;

        return false;
    }

    void print(){
        if(front==-1 && rear==-1) return;
        int i = front;
        while(i!=rear){
            cout<<arr[i]<<" -> ";
            i = (i+1)%capacity;
        }cout<<arr[i]<<" ->\n";
    }


};

int main(){

    fastio

    Queue* q = new Queue(5);
    q->print();
    q->enqueue(2);
    q->enqueue(-1);
    // q->enqueue(5);
    // q->enqueue(6);
    // q->enqueue(7);
    
    // // cout<<q->front<<" "<<q->rear<<"\n";
    // // cout<<(q->rear+1)%5<<'\n';
    // cout<<q->isFull()<<'\n';
    // q->print();
    // cout<<q->peek()<<'\n';
    // q->dequeue();
    // q->dequeue();
    // q->enqueue(32);
    // q->enqueue(324);
    cout<<q->get_size()<<'\n';
    q->print();
    // cout<<q->isFull()<<'\n';



    return 0;
}