#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

//add find and remove_value

class Node{
public:
    int value;
    Node* next;
    Node(int value,Node* next=nullptr){
        this->value=value;
        this->next=next;
    }
};

class LinkedList{//singly linked list
private:
    Node* head;
    int size;
public:
    LinkedList(){
        this->head=NULL;
        this->size=0;
    }

    void insertFront(int value){
        Node* temp=new Node(value,this->head);
        this->head=temp;
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

        if(position>this->size){
            cout<<"Out of bound\n";
            return;
        }
        
        Node* temp=new Node(value);
        Node* current=this->head;
        int idx=0;
        while(position-idx>1){
            current=current->next;
            idx++;
        }
        temp->next=current->next;
        current->next=temp;
        this->size++;
    }

    void insertLast(int value){
        Node* temp=new Node(value);

        if(this->head==NULL){
            this->head=temp;
            this->size++;
            return;
        }

        Node* current=this->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
        this->size++;
    }

    void removeFront(){
        if(this->head==NULL)return;

        Node* temp=this->head;
        this->head=this->head->next;
        this->size--;
        delete temp;
    }

    void removeMiddle(int position){
        if(position>this->size){
            cout<<"Out of bound\n";
            return;
        }

        if(position==0){
            removeFront();
            return;
        }

        Node* current=this->head;
        int index=0;
        while(position-index>1){
            current=current->next;
            index++;
        }
        Node* latter=current->next->next;
        Node* temp=current->next;
        current->next=latter;
        delete temp;
        this->size--;

    }

    void removeLast(){
        if(this->head==NULL)return;

        Node* current=this->head;
        while(current->next->next!=NULL){
            current=current->next;
        }

        Node* lastNode=current->next;
        current->next=NULL;
        delete lastNode;
        this->size--;
    }

    void print(){
        Node* current=this->head;
        while(current!=NULL){
            cout<<current->value<<" -> ";
            current=current->next;
        }
        cout<<endl;
    }
};

int main(){
    fastio;
    LinkedList ll=LinkedList();
    ll.insertFront(2);
    ll.insertFront(3);
    ll.insertMiddle(1,1);
    ll.insertLast(11);
    ll.print();
    
    return 0;
}