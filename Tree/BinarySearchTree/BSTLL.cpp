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

class BinarySearchTree{
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value){
        if(node==nullptr){
            return new TreeNode(value);
        }
        if(value<=node->value){
            node->left = insert(node->left,value);
        }
        else{
            node->right= insert(node->right,value);
        }
        return node;
    }

    void insertIter(TreeNode*& node, int value){
        if(node==nullptr){
            node = new TreeNode(value);
            return;
        }

        TreeNode* curr = node;
        TreeNode* parent = nullptr;

        while(curr!=nullptr){
            parent = curr;
            
            if(value<=curr->value) curr = curr->left;
            else curr = curr->right;
        }

        if(value<=parent->value) parent->left = new TreeNode(value);
        else parent->right = new TreeNode(value);

    }
    
    TreeNode* remove(TreeNode* node, int value){
        if(node==NULL) return node;

        if(value<node->value){
            node->left = remove(node->left,value);
        }
        else if(value> node->value){
            node->right = remove(node->right, value);
        }

        else{
            if(node->left == NULL){
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }


    void removeIter(TreeNode*& root, int value){
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        int level = 0;

        parent = findIter(curr,value,level);

        if(curr==nullptr){
            return;
        }

        if(curr->left==nullptr && curr->right==nullptr){
            if(curr!=root){
                if(parent->left==curr)parent->left = nullptr;
                else parent->right = nullptr;
            }
            else root = nullptr; 

            delete curr;   
        }
        else if(curr->left && curr->right){
            TreeNode* temp = findMin(curr->right);
            curr->value = temp->value;

            removeIter(curr->right,temp->value);
        }   

        else{
            TreeNode* child = (curr->left==nullptr)? curr->right: curr->left;

            if(curr != root){
                if(parent->left==curr) parent->left = child;
                else parent->right = child;
            }
            else root = child;

            delete curr;
        }


    }

    TreeNode* findMin(TreeNode* node){
        while(node->left!=nullptr){
            node = node->left;
        }
        return node;
    }

    TreeNode* find(TreeNode* node, int value, int& level){
        if(node==nullptr){
            level=-1;
            return nullptr;
        }

        level++;
        if(value<node->value) node->left = find(node->left,value,level);
        else if(value>node->value) node->right = find(node->right,value,level);
        return node;
    }

    TreeNode* findIter(TreeNode*& node, int value, int& level){
        TreeNode* curr = node;
        TreeNode* parent = nullptr;

        while(curr!=nullptr && curr->value!=value){
            parent = curr;
            if(value<=curr->value) curr = curr->left;
            else curr = curr->right;
            level++;
        }

        if(curr==nullptr){
            level=-1;
            return nullptr;
        }
        return parent;
    }

    void preorder(TreeNode* node){
        if(node == nullptr) return;

        cout<<node->value<<"->";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(TreeNode* node){
        if(node == nullptr) return;

        inorder(node->left);
        cout<<node->value<<"->";
        inorder(node->right);
    }

    void postorder(TreeNode* node){
        if(node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        cout<<node->value<<"->";
    }

    int height(TreeNode* root){
        if(root==NULL) return 0;

        return 1+ max( height(root->left), height(root->right));
    }

public:
    BinarySearchTree(){
        this->root = nullptr;
    }

    TreeNode* getRoot(){
        return root;
    }

    void addNode(int value){
    //    root = insert(root,value);
        insertIter(root,value);
    }

    void deleteNode(int value){
        root = remove(root,value);
    }

    bool isBalanced(TreeNode* root){  //abs(leftHeight-rightHeight)<=1
        if(root==NULL) return true;
        
        int lh = height(root->left);
        int rh = height(root->right);

        if(isBalanced(root->left) and isBalanced(root->right) and abs(lh-rh)<=1) return true;

        return false;
    }

    //either 0 or 2 children
    bool isFull(TreeNode* root){
        if(root==NULL) return true;

        if(root->left==NULL and root->right==NULL) return true;

        if(root->left and root->right){
            return isFull(root->left) and isFull(root->right);
        }
        return false;
    }


    //all except last level filled, last level filled from left
    bool isComplete(TreeNode* root){
        // Base Case: An empty tree is complete Binary Tree
        if (root == NULL)
            return true;
    
        // Create an empty queue
        queue<TreeNode*> q;
    
        // Create a flag variable which will be set true
        // when a non-full node is seen
        bool flag = false;
    
        // Do level order traversal using queue.
        q.push(root);
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
    
            /* Check if left child is present*/
            if (temp->left)
            {
                // If we have seen a non-full node, and we see a node
                // with non-empty left child, then the given tree is not
                // a complete Binary Tree
                if (flag == true)
                    return false;
    
                // Enqueue Left Child
                q.push(temp->left);
            }
            else // If this a non-full node, set the flag as true
                flag = true;
    
            /* Check if right child is present*/
            if (temp->right)
            {
                // If we have seen a non full node, and we see a node
                // with non-empty right child, then the given tree is not
                // a complete Binary Tree
                if (flag == true)
                    return false;
    
                // Enqueue Right Child
                q.push(temp->right);
            }
            else // If this a non-full node, set the flag as true
                flag = true;
        }
    
        /* If we reach here, then the tree is complete Binary Tree*/
        return true;
    }
    
    //all nodes except leaf have two children, all leaf at same level
    bool checkPerfect(TreeNode* root, int level,int depth){
        if(root==NULL) return true;
        
        if(root->left==NULL && root->right==NULL)
            return depth==level+1;

        if(root->left==NULL || root->right==NULL)
            return false;
        
        return checkPerfect(root->left,level+1,depth) && checkPerfect(root->right,level+1,depth);
    }

    bool isPerfect(TreeNode* root){
        int lh = height(root);
        return checkPerfect(root,0,lh);
    }

    bool isDegenerate(TreeNode* root){
        if(root==NULL) return true;

        if(root->left!=NULL and root->right!=NULL) 
            return false;

        if(root->left==NULL) return isDegenerate(root->right);
        else return isDegenerate(root->left);
    }

    bool isLeftSkewed(TreeNode* root){
        int rh = height(root->right);
        return rh==0;
    }
    bool isRightSkewed(TreeNode* root){
        int lh = height(root->left);
        return lh==0;
    }

    int search(int value){
        int level=0;
        root = find(root,value,level);
        // findIter(root,value,level);
        return level;
    }

    void printPreOrder(){
        preorder(root);
        cout<<'\n';
    }

    void printInorder(){
        inorder(root);
        cout<<'\n';
    }

    void printPostOrder(){
        postorder(root);
        cout<<'\n';
    }
};

// int main(){

//     fastio

//     BinarySearchTree t = BinarySearchTree();
//     t.addNode(2);
//     t.addNode(1);
//     t.addNode(6);
//     // cout<<t.search(2)<<'\n';
//     // cout<<t.search(6)<<'\n';
//     cout<<t.search(5)<<'\n';

//     // t.deleteNode(9);

//     t.printPreOrder();
//     t.printInorder();
//     t.printPostOrder();

    

//     return 0;
// }