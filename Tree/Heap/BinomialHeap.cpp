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
    int value, degree;
    Node* parent;
    Node* leftChild;
    Node* sibling;

    Node(int value){
        this->value = value;
        this->degree=0;
        this->leftChild = NULL;
        this->parent = NULL;
        this->sibling = NULL;
    }
};

class BinomialHeap{
private:
    Node* mergeRootList(Node* root1, Node* root2){
        Node* root3 = new Node(0);
        Node* temp = root3;

        while(root1 != NULL && root2 != NULL){
            if(root1->degree <= root2->degree){
                temp->sibling = root1;
                root1 = root1->sibling;
            }
            else{
                temp->sibling = root2;
                root2 = root2->sibling;
            }
            temp = temp->sibling;
        }

        while(root1 != NULL){
            temp->sibling = root1;
            root1 = root1->sibling;
            temp = temp->sibling;
        }

        while(root2 != NULL){
            temp->sibling = root2;
            root2 = root2->sibling;
            temp = temp->sibling;
        }




        return root3->sibling;

    }

    Node* find_minNode(){
        Node* a = root;
        Node* smallest = root;
        while(a!=NULL){
            if(a->value<smallest->value) smallest = a;
            a = a->sibling;
        }
        return smallest;
    }

    Node* reverse(Node* root){
        Node* prev = NULL;
        Node* temp = root;
        Node* next = NULL;

        while(temp != NULL){
            next = temp->sibling;

            temp->sibling = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

public:
    Node* root;

    BinomialHeap(){
        root = NULL;
    }

    void merge(BinomialHeap* other){
        Node* root1 = this->root;
        Node* root2 = other->root;

        Node* newRoot = mergeRootList(root1,root2);


        root = newRoot;
        if(root==NULL) return;

        Node* prev = NULL;
        Node* curr = root;
        Node* next = curr->sibling;

        while (next != NULL){
            if (curr->degree != next->degree || (next->sibling != NULL && next->sibling->degree == curr->degree))
            {
                prev = curr;
                curr = next;
            }
            else if (curr->value <= next->value)
            {
                curr->sibling = next->sibling;
                next->parent = curr;
                next->sibling = curr->leftChild;
                curr->leftChild = next;
                curr->degree++;
            }
            else
            {
                if (prev == NULL)
                {
                    newRoot = next;
                }
                else
                {
                    prev->sibling = next;
                }
                curr->parent = next;
                curr->sibling = next->leftChild;
                next->leftChild = curr;
                next->degree++;
                curr = next;
            }

            next = curr->sibling;
        }

        root = newRoot;

    }

    int find_min(){
        return find_minNode()->value;
    }

    int extract_min(){
        Node* res = find_minNode();
        int value = res->value;
        Node* temp = res->leftChild;
        delete res;

        Node* newRoot = temp;
        newRoot = reverse(newRoot);
        BinomialHeap* newHeap = new BinomialHeap();
        newHeap->root = newRoot;

        merge(newHeap);
        return value;
    }

    void insert(int value){
        BinomialHeap* newHeap = new BinomialHeap();
        newHeap->root = new Node(value);

        merge(newHeap);
    }

    void decrease_key(Node* node, int newValue){
        if(newValue >= node->value) return;
        node->value = newValue;

        while(node->parent!=NULL && node->parent->value > node->value){
            swap(node->parent->value,node->value);
            node = node->parent;
        }
    }

    void deleteNode(Node* node){
        decrease_key(node, INT_MIN);
        extract_min();
    }

    void printRootList(){
        Node* a2 = this->root;
        while(a2!=NULL){
            cout<<a2->value<<" ";
            a2 = a2->sibling;
        }cout<<'\n';
    }


};


int main(){

    fastio

    BinomialHeap* a = new BinomialHeap();
    a->insert(7);
    a->insert(25);

    BinomialHeap* b = new BinomialHeap();
    b->insert(12);
    b->insert(30);

    BinomialHeap* c= new BinomialHeap();
    c->insert(1);
    c->insert(5);


    b->merge(a);
    cout<<b->find_min()<<'\n';

    
    cout<< b->root->degree<<'\n';
    b->merge(c);
    cout<< b->root->degree<<'\n';

    cout<<b->find_min()<<'\n';

    // BinomialHeap* b1 = new BinomialHeap();
    // b1->root= new Node(7);
    // Node* x = new Node(25);
    // b1->root->leftChild = x;
    // x->parent = b1->root;
    // b1->root->degree++;


    // BinomialHeap* b2 = new BinomialHeap();
    // b2->root = new Node(12);
    // Node* y = new Node(30);
    // b2->root->leftChild = y;
    // y->parent = b2->root;
    // b2->root->degree++;
   
    // b2->merge(b1);
    // Node* a = b2->root;
    // while(a!=NULL){
    //     cout<<a->value<<" ";
    //     a = a->sibling;
    // }cout<<'\n';

    // BinomialHeap* b3 = new BinomialHeap();
    // b3->root = new Node(1);

    // b2->merge(b3);
    // // cout<<b2->root->value<<"\n";

    // BinomialHeap* b4 = new BinomialHeap();
    // b4->root = new Node(5);

    // b2->merge(b4);
    
    // a = b2->root;
    // while(a!=NULL){
    //     cout<<a->value<<" ";
    //     a = a->sibling;
    // }cout<<'\n';

    // cout<<b2->extract_min()<<'\n';
    // cout<<b2->find_min()<<'\n';

    return 0;
}