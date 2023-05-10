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

//*****************************************
//NOT FINISHED
//*****************************************
class Queue{
private:
    int *st1,*st2;
    int top1, top2;
    int capacity;

public:
    Queue(int capacity){
        this->capacity = capacity;
        top1=-1;top2=-1;
        st1 = new int[capacity];
        st2 = new int[capacity];
    }
    
    int getSize(){
        return top1+1;
    }

    void enqueue(int value){
        if(top1==capacity-1) return;

        st1[++top1]=value;
    }

    void dequeue(){     
        for (int i = top1; i >= 0; i--)
        {
            st2[top1-i]=st1[i];
        }
        top2 = top1-1;

        for (int i = top2; i >= 0; i--)
        {
            st1[top2-i] = st2[i];
        }
        top1 = top2;
        
    }

    int peek(){
        return st1[0];
    }

    void print(){
        for (int i = top1; i >= 0; i--)
        {
            st2[top1-i]=st1[i];
        }
        
        top2 = top1;

        for (int i = top2; i >= 0; i--)
        {
            cout<<st2[i]<<" -> ";
        }cout<<'\n';
        
    }
};

int main(){

    fastio

    Queue* q = new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->print();
    cout<<q->peek()<<'\n';
    q->dequeue();
    // q->enqueue(2);
    q->print();
    cout<<q->peek()<<'\n';
    cout<<q->getSize()<<'\n';

    return 0;
}