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

    Node(int value, Node* next = nullptr){
        this->value=value;
        this->next = next;
    }
};

class queue{
private:
    int size;
    Node* front;
    Node* rear;

public:
    queue(){
        front = rear = nullptr;
        this->size = 0;
    }

    int get_size(){
        return this->size;
    }

    void enqueue(int value){
        Node* newNode = new Node(value,front);
        if(front==nullptr && rear == nullptr){
            front = rear= newNode;
            rear->next = front;
        }

        else{
            rear->next = newNode;
            rear = rear->next;
        }
        
        this->size++;
    }
 
    void dequeue(){
        if(front==nullptr && rear==nullptr) return;

        Node* temp = front;
        if(front==rear){
            front = rear = nullptr;
        }
        else{
            front = front->next;
            rear->next = front;
        }
        delete temp;
        this->size--;
    }

    int peek(){
        if(front==nullptr) return INT_MIN;

        return this->front->value;
    }

    void print(){
        if(front==nullptr && rear==nullptr) return;
        Node* currNode = front;

        do
        {
            cout<<currNode->value<<" -> ";
            currNode = currNode->next;
        } while (currNode!=front);
        cout<<'\n';
        

        // while(1){
        //     cout<<currNode->value<<" -> ";
        //     currNode = currNode->next;

        //     if(currNode==front) break;
        // }cout<<'\n';
    }
};

int main(){

    fastio

    queue* q = new queue();
    q->enqueue(1);
    q->enqueue(2);
    // q->enqueue(3);
    // q->print();
    // q->dequeue();
    q->print();
    cout<<q->peek()<<'\n';

    return 0;
}