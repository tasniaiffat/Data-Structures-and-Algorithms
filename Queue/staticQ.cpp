#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

class Queue{
private:
    int capacity;
    int *st;
    int size;
    int head;
    int tail;
public:
    Queue(int capacity){
        this->capacity=capacity;
        this->st=new int[capacity];
        this->size=0;
        this->head=-1;
        this->tail=-1;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }

        if(isEmpty()){
            this->head++;
        }
        this->tail++;
        st[this->tail]=value;
        this->size++;
    }

    bool isEmpty(){
        return this->head==-1;
    }

    bool isFull(){
        return this->size==this->capacity;
    }

    int getSize(){
        return this->size;
    }

};

int main(){
    fastio
    
    return 0;
}