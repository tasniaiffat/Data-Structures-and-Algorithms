#include<bits/stdc++.h>
#include<time.h>
using namespace std;
void randomArr(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

class Stack
{
private:
    int capacity;
    int* st;
    int top;
    int size;
public:
    Stack(int capacity);
    bool push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
    int get_capacitty();
    int get_size();
    void clear();
    int search(int value);
};

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    this->st = (int*)malloc(capacity*sizeof(int));
    this->top=-1;
    this->size=0;
}

bool Stack::push(int value){
    if(this->isFull()){
        cout<<"Stack overflow\n";
        return false;
    }

    this->st[++this->top]=value;
    this->size++;
    return true;
}

int Stack::pop(){
    if(this->isEmpty()){
        cout<<"Stack Underflow\n";
        return INT_MIN;
    }

    int value = this->st[top];
    this->top--;
    this->size--;
    return value;
}

int Stack::peek(){
    if(this->isEmpty()){
        cout<<"Stack is Empty\n";
        return INT_MIN;
    }
    return this->st[this->top];
}

bool Stack::isEmpty(){
    if(this->top==-1) return true;
    else return false;
}

bool Stack::isFull(){
    if(this->top==this->capacity-1) return true;
    else return false;
}

void Stack::print(){
    for (int i = this->top; i >-1; i--)
    {
        cout<<"| "<<st[i]<<" |\n";
    }cout<<"_____\n";
    
}

int Stack::get_capacitty(){
    return this->capacity;
}

int Stack::get_size(){
    return this->size;
}

void Stack::clear(){
    this->top=-1;
}
int Stack::search(int value){
    for (int i = this->top; i >=0 ; i--)
    {
        if(this->st[i]==value) return this->top-i;
    }
    return -1;
}


int main(){
    int arr[150];
    int n=150;

    randomArr(arr,n);

    stack<int> inputStack;
    stack<int> tempStack;

    for(int i=0;i<n;i++){
        inputStack.push(arr[i]);
        cout<< arr[i] << " ";
    }
    cout << endl;

    while(!inputStack.empty())
    {
        int currentElement=inputStack.top();
        //cout << currentElement << " ";
        inputStack.pop();
        if(tempStack.empty())tempStack.push(currentElement);
        else if(currentElement>=tempStack.top())tempStack.push(currentElement);
        else{
            while(!tempStack.empty() and currentElement<tempStack.top())
            { 
                inputStack.push(tempStack.top());
                tempStack.pop();
            }

            tempStack.push(currentElement);
        }
        //cout << "\n";

    }

    while(!tempStack.empty())
    {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }

    while(!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }

    
}