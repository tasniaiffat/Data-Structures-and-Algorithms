#include<bits/stdc++.h>
// #include<E:\Prog stuffs\DataStructures\LinkedList\C++\LinkedList.hpp>

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

    Node(int value, Node* next=nullptr){
        this->value=value;
        this->next = next;
    }
};


class DynamicQueue{
private:
    Node* front;
    Node* rear;
    int size;

public:

    DynamicQueue(){
        this->front = nullptr;
        this->rear = nullptr;
        this->size=0;
    }

    int get_size(){
        return this->size;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        if(front==nullptr){
            front=newNode;
            rear = newNode;
            this->size++;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
        this->size++;
    }

    void dequeue(){
        if(front==nullptr) return;
        Node* temp = front;
        front = front->next;
        this->size--;
        delete temp;
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



// class LL: public LinkedList{
// private:
//     Node* tail;

// public:
//     LL(){
        
//         this->tail = nullptr;
//     }

//     Node* get_tail(){
//         return this->tail;
//     }

//     void insert_last(int value){
        
//         // Node* current = this->head;
//         Node* newNode = new Node(value);
    
//         if(this->get_head() == nullptr){
//             // this->head = newNode;
//             this->set_head(newNode);
//             this->tail = newNode;
//             // this->size++;
//             this->increase_size();
//             return;
//         }

//         // while(current->next!=nullptr){
//         //     current = current->next;
//         // }

//         this->tail->next = newNode;
//         this->tail = newNode;
//         this->increase_size();

//         // current->next = newNode;
//         // this->size++;
//     }
// };

// class DynamicQueue{
// private:
//     LL* arr;
//     Node* front;
//     Node* rear;

// public:
//     DynamicQueue(){
        
//         arr = new LL();
//         front = arr->get_head();
//         rear = arr->get_head();
//     }

//     void enqueue(int value){
//         arr->insert_last(value);

//         front = arr->get_head();
//         rear = arr->get_tail();
//     } 

//     void dequeue(){
//         if(front==nullptr) return;

//         arr->remove_front();
//         front = arr->get_head();
//     }

//     int peek(){
//         if(front==nullptr) return INT_MIN;
//         return front->value;
//     }

//     void print(){
//         arr->print();
//     }

// };



int main(){

    fastio

   DynamicQueue* q = new DynamicQueue();
   q->enqueue(1);
   q->enqueue(2);
   q->enqueue(3);
   q->dequeue();
   cout<<q->peek()<<'\n';
   
   q->print();

    return 0;
}