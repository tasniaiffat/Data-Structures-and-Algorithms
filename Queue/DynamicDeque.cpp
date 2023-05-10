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

class Node{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value,Node* prev = nullptr, Node* next = nullptr){
        this->value= value;
        this->next = next;
        this->prev = prev;
    }
};

class Deque{
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque(){
        front = rear = nullptr;
        size=0;
    }

    void insertFront(int value){
        Node* newNode = new Node(value);
        if(front==nullptr){
            front = rear = newNode;
        }
        else{
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        this->size++;
    }

    void insertBack(int value){
        Node* newNode = new Node(value);
        if(rear==nullptr){
            front = rear = newNode;
        }
        else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        this->size++;
    }


    int removeFront(){
        if(front==nullptr) return INT_MIN;
        int val = front->value;
        if(front==rear){
            front = rear = nullptr;
        }
        else{
            front = front->next;
            front->prev = nullptr;
        }
        this->size--;
        return val;
    }

    int removeBack(){
        if(rear==nullptr) return INT_MIN;
        int val = rear->value;
        if(front==rear){
            front = rear = nullptr;
        }
        else{
            rear= rear->prev;
            rear->next = nullptr;
        }
        this->size--;
        return val;
    }

    int peek(){
        if(front==nullptr) return INT_MIN;
        return front->value;
    }

    void print(){
        Node* currNode = this->front;

        while(currNode!=nullptr){
            cout<<currNode->value<<" -> ";
            currNode = currNode->next;
        }cout<<'\n';
        
    }

};

int main(){

    fastio

    Deque q = Deque();
    q.insertFront(1);
    q.insertBack(2);
    q.insertFront(3);
    q.print();
    

    return 0;
}