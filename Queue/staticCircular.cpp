#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


//diy

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
        if(front==-1 && rear==-1){
            front=rear=0;
            arr[rear]=value;
            this->size++;
            return;
        }

        else if((rear+1)%capacity==front)return;
        else{
            rear=(rear+1)%capacity;
            arr[rear]=value;
            this->size++;
        }
    }

    int dequeue(){
        if(front==-1)return;
        if(front=rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        this->size--;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            exit(1);
        }

        return arr[front];
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