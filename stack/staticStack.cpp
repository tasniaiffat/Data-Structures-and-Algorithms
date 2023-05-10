#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

class Stack{
private:
    int capacity;
    int *st;
    int size;
    int top;
public:
    Stack(int capacity){
        this->capacity=capacity;
        this->st=new int[capacity];
        this->top=-1;
        this->size=0;
    }
    void push(int value){
        if(isFull()){
            cout<<"Stack Overflow\n";
            return;
        }

        this->top++;
        st[this->top]=value;
        this->size++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            exit(1);
        }
        int value=st[this->top];
        this->top--;
        this->size--;
        return value;
    }

    int peek(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            exit(1);
        }
        return st[this->top];
    }

    void print(){
        for(int i=this->top;i>=0;i--){
            cout<<st[i]<<" ";
        }cout<<endl;
    }

    bool isEmpty(){
        return this->size==0;
    }

    bool isFull(){
        return this->size==this->capacity;
    }

    int getSize(){
        return this->size;
    }

    void clear(){
        this->top=-1;
        this->size=0;
    }

    int search(int value){
        int flag=0;
        for(int i=this->top;i>=0;i--){
            if(st[i]==value){
                flag=1;
                return this->top-i;//returns position, staring from top=0
                break;
            }
        }
        if(flag==0)return -1;
    }
};

int main(){
    fastio
    Stack st=Stack(3);

    st.push(2);
    st.push(4);
    cout<<st.pop()<<endl;
    st.push(3);
    cout<<st.isEmpty()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;

    return 0;
}