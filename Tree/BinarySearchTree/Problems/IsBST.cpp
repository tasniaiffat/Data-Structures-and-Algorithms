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

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

bool isBST(TreeNode* root, int minkey, int maxkey){
    if(root==nullptr) return true;

    if(root->value< minkey || root->value > maxkey){
        return false;
    }

    return isBST(root->left,minkey,root->value) && isBST(root->right,root->value,maxkey);
}

// Function to perform inorder traversal on the given binary tree and
// check if it is a BST or not. Here, `prev` is the previously processed node
bool isBST(TreeNode* root, TreeNode* &prev) 
{
    // base case: empty tree is a BST
    if (root == nullptr) {
        return true;
    }
 
    // check if the left subtree is BST or not
    bool left = isBST(root->left, prev);
 
    // value of the current node should be more than that of the previous node
    if (root->value <= prev->value) {
        return false;
    }
 
    // update the previous node and check if the right subtree is BST or not
    prev = root;
    return left && isBST(root->right, prev);
}
 
// Function to determine whether a given binary tree is a BST
void isBST(TreeNode* node)
{
    // pointer to store previously processed node in the inorder traversal
    TreeNode* prev = new TreeNode(INT_MIN);
 
    // check if nodes are processed in sorted order
    if (isBST(node, prev)) {
        printf("The tree is a BST.");
    }
    else {
        printf("The tree is not a BST!");
    }
}

int main(){

    fastio

    

    return 0;
}