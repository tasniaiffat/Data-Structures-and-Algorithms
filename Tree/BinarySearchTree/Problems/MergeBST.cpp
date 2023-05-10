#include<bits/stdc++.h>
#include<E:\Prog stuffs\DataStructures\Tree\BinarySearchTree\BinarySearchTree.hpp>
#include<E:\Prog stuffs\DataStructures\LinkedList\C++\LinkedList.hpp>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

// const int N = 1e7+10;

// class TreeNode{
// public:
//     int value;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr){
//         this->value = value;
//         this->left = left;
//         this->right = right;
//     }
// };

void inorder(TreeNode* root, LinkedList* ans){
    if(root==nullptr) return;

    inorder(root->right,ans);
    ans->insert_front(root->value);
    inorder(root->left,ans);
}

LinkedList* BSTtoLL(BinarySearchTree* b){
    LinkedList* ans = new LinkedList();

    TreeNode* root = b->getRoot();

    inorder(root,ans);

    return ans;

}

LinkedList* merge(BinarySearchTree* a, BinarySearchTree* b){
    LinkedList* l1 = BSTtoLL(a);
    LinkedList* l2 = BSTtoLL(b);
    LinkedList* l3 = new LinkedList();

    Node* head1 = l1->get_head();
    Node* head2 = l2->get_head();

    while(head1!= nullptr && head2!=nullptr){
        if(head1->value<=head2->value){
            l3->insert_last(head1->value);
            head1 = head1->next;
        }
        else{
            l3->insert_last(head2->value);
            head2 = head2->next;
        }
    }
    while(head1!=nullptr){
        l3->insert_last(head1->value);
        head1 = head1->next;
    }
    while(head2!=nullptr){
        l3->insert_last(head2->value);
        head2 = head2->next;
    }

    return l3;
}


int main(){

    fastio

    BinarySearchTree* a = new BinarySearchTree();
    BinarySearchTree* b = new BinarySearchTree();

    b->addNode(20);
    b->addNode(10);
    b->addNode(30);
    b->addNode(25);
    b->addNode(100);

    a->addNode(50);
    a->addNode(5);
    a->addNode(70);

    LinkedList* ans = merge(a,b);

    ans->print();

    return 0;
}