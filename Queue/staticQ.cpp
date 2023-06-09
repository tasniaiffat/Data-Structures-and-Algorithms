#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

class Queue{
private:
    int capacity;
    int *arr;
    int size;
    int front;
    int rear;
public:
    Queue(int capacity){
        this->capacity=capacity;
        this->arr=new int[capacity];
        this->size=0;
        this->front=-1;
        this->rear=-1;
    }

    bool isEmpty(){
        return this->size==0;
    }

    bool isFull(){
        return this->size==this->capacity;
    }

    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }

        if(isEmpty()){
            this->front++;
            this->rear++;
            arr[this->front]=value;
            this->size++;
            return;
        }

        this->rear++;
        arr[this->rear]=value;
        this->size++;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            exit(1);
        }

        int value=arr[this->front];
        this->front++;
        this->size--;
        return value;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            exit(1);
        }

        int value=arr[this->front];
        return value;
    }

    void print(){
        for(int i=this->front;i<=this->rear;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    int getSize(){
        return this->size;
    }
    

};

int main(){
    fastio

    Queue q=Queue(100);
    q.enqueue(1);
    q.enqueue(4);
    q.dequeue();
    
    q.dequeue();
    q.dequeue();

    q.print();
    
    return 0;
}