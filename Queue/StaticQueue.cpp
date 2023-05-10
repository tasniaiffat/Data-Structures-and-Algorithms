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

class StaticQueue{
private:
    int* arr;
    int capacity;
    int size;
    int front, rear;

public:
    int* get_arr(){return arr;}

    int get_capacity(){return this->capacity;}

    int get_size(){return this->size;}

    void increase_size(){this->size++;}
    void decrease_size(){this->size--;}
    void set_size(int size){this->size = size;}

    int get_front(){return this->front;}

    void increase_front(){this->front++;}
    void decrease_front(){this->front--;}
    void set_front(int front){this->front = front;}

    int get_rear(){return this->rear;}

    void increase_rear(){this->rear++;}
    void decrease_rear(){this->rear--;}
    void set_rear(int rear){this->rear = rear;}


    StaticQueue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        this->size=0;
        front = rear = -1;
    }


    void enqueue(int value){
        // if(this->size>capacity) return;
        if(this->rear==capacity-1) return;

        arr[++rear]=value;

        if(front<0) front++;

        this->size++;

    }

    void dequeue(){
        if(front==rear){
            front=rear=-1;
            this->size=0;
            return;
        }
        
        front++;
        this->size--;
    }

    int peek(){
        return arr[front];
    }

    bool isFull(){
        if(this->size==capacity)
            return true;
        return false;
    }

    bool isEmpty(){
        if(this->size==0)
            return true;
        return false;
    }

    void print(){
        for (int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" -> ";
        }cout<<'\n';
        
    }
};

int main(){

    fastio

    StaticQueue* q  = new StaticQueue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->print();
    q->dequeue();
    q->print();
    cout<<q->peek()<<'\n';
    int size = q->get_size();
    cout<<size<<'\n';
    

    return 0;
}