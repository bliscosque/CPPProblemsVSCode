#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

int last=INT_MIN;

bool isBSTrec(Node * root) {
    bool ans=true;
    if (root==NULL) return true;
    ans=ans && isBSTrec(root->left);
    if (root->key >=last) {
        last=root->key;
    }
    else {
        ans=false;
    }
    ans=ans && isBSTrec(root->right);
    return ans;
}

bool isBST(Node * root){
    last=INT_MIN;    
    return isBSTrec(root);   
    
}


Node* insert(Node* root, int key) {
    if (root==NULL) {
        return new Node(key);
    }
    if(key<root->key) {
        root->left=insert(root->left,key);
    }
    else {
        root->right=insert(root->right,key);
    }
    return root;
}

void printInOrder(Node* root) {
    if (root==NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->key << ",";
    printInOrder(root->right);
}

int main() {
    Node* root=NULL;
    vector<int> a = {8,3,10,1,6,14,4,7,13};

    for (int x:a) {
        //cout << x << endl;
        root=insert(root,x);
    }
    printInOrder(root);

    cout << endl << endl;
    cout << isBST(root) << endl << endl;
    

    return 0;
}

/* SOLUCAO DO AUTOR

#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

bool isBSTUtil(Node* node, int min, int max)
{
    // an empty tree is BST 
    if (node==NULL)
        return true;
             
    // false if this node violates
    //the min/max constraint 
    if (node->key < min || node->key > max)
        return false;
     
    // otherwise check the subtrees recursively,
    tightening the min or max constraint 
    return
        isBSTUtil(node->left, min, node->key) &&
        isBSTUtil(node->right, node->key, max); 
}

bool isBST(Node * root){
    //complete this method
    return isBSTUtil(root, INT_MIN,INT_MAX);
    
}

*/