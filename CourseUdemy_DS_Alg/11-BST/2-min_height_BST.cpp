//given a sorted array, construct a BST of minimun height.
//sol: insere mid no nó;
//     de start ate mid-1, insere a esquerda;
//     de mid+1 ate end, insere a direita

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key=key;
        left=right=NULL;
    }
};

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

bool isPresent(Node * root,int key){
    if(root==NULL) {
        return false;
    }    
    else if (key==root->key) {
        return true;
    }
    else if (key<root->key) {
        return isPresent(root->left,key);
    }
    else {
        return isPresent(root->right,key);
    }
}

Node* sortedArrayToBST(vector<int> arr, int start, int end) 
{
    if (start>end) {
        return NULL;
    }
    int mid=(start+end)/2;

    Node* root=new Node(arr[mid]);
    
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);

    return root;

}


int main() {
    Node* root=NULL;
    vector<int> a = {1,2,3,4,5,6,7};

    root=sortedArrayToBST(a, 0 , a.size()-1);

    printInOrder(root);
    

    return 0;
}