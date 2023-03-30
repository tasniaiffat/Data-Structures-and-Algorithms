#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

class Node{
public:
    int value;
    Node* next;
    Node(int value,Node* next=nullptr){
        this->value=value;
        this->next=next;
    }
};

class Stack{
private:
    Node* top;
    int size;
public:
    Stack(){
        this->top=NULL;
        this->size=0;
    }

    void push(int value){
        Node* temp=new Node(value,this->top);
        this->top=temp;
        this->size++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            exit(1);
        }
        Node* temp=this->top;
        int value=temp->value;
        top=top->next;
        delete temp;
        this->size--;
        return value;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            exit(1);
        }
        return this->top->value;
    }

    bool isEmpty(){
        return this->top==NULL;
    }

    void clear(){
        this->top=NULL;
        this->size=0;
    }

    int search(int value){
        int pos=0;
        Node* current=this->top;
        while(current!=NULL){
            if(current->value==value){
                return pos;
            }
            current=current->next;
            pos++;
        }
        return -1;//not found
    }

    void print(){
        Node* current=this->top;
        while(current!=NULL){
            cout<<current->value<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};

int main(){
    fastio;
    Stack st=Stack();
    st.push(1);
    st.push(2);
    st.push(4);
    cout<<st.search(3);
    return 0;
}