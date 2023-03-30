#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

class Node{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value,Node* next=nullptr,Node* prev=nullptr){
        this->value=value;
        this->next=next;
        this->prev=prev;
    }
};

class LinkedList{//doubly linked list
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }

    bool isEmpty(){
        return this->head==NULL;
    }

    void insertFront(int value){
        Node* temp=new Node(value,this->head);
        if(isEmpty()){
            this->head=temp;
            this->tail=temp;
            this->size++;
            return;
        }

        this->tail->next=temp;
        this->head->prev=temp;
        this->head=temp;
        this->size++;
    }

    void insertLast(int value){
        
        if(isEmpty()){
            insertFront(value);
            return;
        }
        Node* temp=new Node(value);
        temp->prev=this->tail;
        this->tail->next=temp;
        this->tail=temp;
        this->size++;
    }

    void insertMiddle(int value,int position){
        if(position==0){
            insertFront(value);
            return;
        }

        if(position==this->size){
            insertLast(value);
            return;
        }

        if(position>this->size)return;

        Node* temp=new Node(value);
        Node* current=this->head;
        int idx=0;
        while(position-idx>1){
            current=current->next;
            idx++;
        }
        temp->prev=current;
        temp->next=current->next;
        current->next->prev=temp;
        current->next=temp;
        this->size++;
    }

    void removeFront(){
        if(isEmpty())return;
        Node* temp=this->head;
        if(this->head==this->tail){//only 1 element
            this->tail=NULL;
        }
        
        this->head=temp->next;
        this->head->prev=NULL;
        this->size--;
        delete temp;
    }

    void removeLast(){
        if(isEmpty())return;

        if(this->head==this->tail){
            this->head=NULL;
        }

        Node* temp=this->tail;
        this->tail=temp->prev;
        this->tail->next=NULL;
        this->size--;
        delete temp;
    }

    void removeMiddle(int position){
        if(isEmpty()||position>=this->size){
            return;
        }

        if(position==0){
            removeFront();
            return;
        }

        if(position==(this->size-1)){
            removeLast();
            return;
        }

        Node* current=this->head;
        int idx=0;
        while(position-idx>1){
            current=current->next;
            idx++;
        }
        Node* latter=current->next->next;
        Node* temp=current->next;
        current->next=latter;
        latter->prev=current;
        this->size--;
    }

    void print_forward(){//begin to end
        Node* current=this->head;
        while(current!=this->tail){
            cout<<current->value<<" -> ";
            current=current->next;
        }cout<<current->value<<endl;
    }

    void print_backward(){//end to begin
        Node* current=this->tail;
        while(current!=this->head){
            cout<<current->value<<" -> ";
            current=current->prev;
        }cout<<current->value<<endl;
    }
};

int main(){
    fastio
    LinkedList ll=LinkedList();
    ll.insertFront(3);
    ll.insertFront(4);
    ll.insertLast(2);
    ll.removeMiddle(2);
    ll.print_forward();

    return 0;
}