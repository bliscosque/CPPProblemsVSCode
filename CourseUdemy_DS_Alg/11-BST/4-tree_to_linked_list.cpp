//given a BST, convert it to a sorted linked list. Right pointer should behave as next pointer for the linked list

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

class LinkedList {
public:
    Node* head;
    Node* tail;
};

LinkedList tree2LL (Node * root) {
    LinkedList ll;
    if (root==NULL) {
        ll.head=ll.tail=NULL;
        return ll;
    }
    if (root->left==NULL && root->right==NULL) { //folha
        ll.head=ll.tail=root;
        return ll;
    }
    else if (root->left!=NULL && root->right==NULL) {
        LinkedList leftLL=tree2LL(root->left);
        leftLL.tail->right=root;

        ll.head=leftLL.head;
        ll.tail=root;
    }
    else if (root->left==NULL && root->right!=NULL) {
        LinkedList rightLL=tree2LL(root->right);
        root->right=rightLL.head;

        ll.head=root;
        ll.tail=rightLL.tail;
    }
    else { //none is null
        LinkedList leftLL=tree2LL(root->left);
        LinkedList rightLL=tree2LL(root->right);
        leftLL.tail->right=root;
        root->right=rightLL.head;
        ll.head=leftLL.head;
        ll.tail=rightLL.tail;
    }
    return ll;
}


int main() {
    Node* root=NULL;
    vector<int> a = {1,2,3,4,5,6,7};

    root=sortedArrayToBST(a, 0 , a.size()-1);

    printInOrder(root);
    
    cout << endl;
    
    LinkedList ll=tree2LL(root);
    Node* r2=ll.head;
    while (r2!=NULL){
        cout << r2->key << ",";
        r2=r2->right;
    }


    return 0;
}