//function to find the integer closest to a given target value

#include <iostream>
#include <vector>
#include <climits>
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

int FindClosestInBST(Node* root, int target) {

    int closest;
    int diff=INT_MAX;

    Node *temp=root;

    while (temp!=NULL) {
        int currDif = abs(temp->key-target);
        if (currDif==0) return temp->key;
        if (currDif<diff) {
            diff=currDif;
            closest=temp->key;
        }
        if (temp->key < target) {
            temp=temp->right;
        }
        else temp=temp->left;
    }
    return closest;
}

int main() {
    Node* root=NULL;
    vector<int> a = {1,2,3,4,5,6,7};

    root=sortedArrayToBST(a, 0 , a.size()-1);

    printInOrder(root);
    
    cout << endl;
    
    cout << FindClosestInBST(root,4) << endl;
    cout << FindClosestInBST(root,8) << endl;

    return 0;
}