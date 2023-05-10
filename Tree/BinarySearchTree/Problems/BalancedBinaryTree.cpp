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

int getHeight(TreeNode* node){
    if(node==nullptr) return 0;

    return 1+ max(getHeight(node->left),getHeight(node->right));
}


bool isBalanced(TreeNode* root){
    if(root==nullptr) return true;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;

    return false;
}

int checkBalanced(TreeNode* root){          //optimized
    if(root==nullptr) return 0;

    int lh = checkBalanced(root->left);

    if(lh == -1) return -1;

    int rh = checkBalanced(root->right);

    if(rh == -1) return -1;

    if(abs(lh-rh)>1) return -1;

    return max(lh,rh)+1;
}


void constructBalancedBST(TreeNode*& root, int arr[], int lo, int hi){
    if(lo>hi) return;

    int mid = (lo+hi)/2;

    root = new TreeNode(arr[mid]);

    constructBalancedBST(root->left, arr, lo,mid-1);
    constructBalancedBST(root->right, arr, mid+1,hi);
}

TreeNode* convert(int arr[], int n){
    sort(arr,arr+n);
    TreeNode* root = nullptr;
    constructBalancedBST(root,arr,0,n-1);
    return root;
}

void inorder(TreeNode* node){
    if(node == nullptr) return;

    inorder(node->left);
    cout<<node->value<<"->";
    inorder(node->right);
}





int main(){

    fastio
    
    // Node* root = new Node(10);
    // root->left = new Node(5);
    // root->right = new Node(30);
    // root->right->left = new Node(15);
    // root->right->right = new Node(20);
 
    // if (isBalanced(root) >= 0)
    //     cout << "Balanced";
    // else
    //     cout << "Not Balanced";
    // return 0; 

    int arr[]= { 15, 10, 20, 8, 12, 16, 25 };
 
    // construct a balanced binary search tree
    TreeNode* root = convert(arr,7);
 
    // print the keys in an inorder fashion
    inorder(root);

    return 0;
}