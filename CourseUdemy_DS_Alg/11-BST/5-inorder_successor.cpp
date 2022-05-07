//given a BST, find the inorder successor of a given target node
//1) look in the right subtree, in the extreme left
//2) the right subtree does not exist. From root, every time I see node->data > target (store update successor)

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

Node* inorderSucc(Node* root, Node* target) {
    //if right subtree exists
    if (target->right!=NULL) {
        Node* temp=target->right;
        while(temp->left!=NULL) {
            temp=temp->left;
        }
        return temp;
    }
    //otherwise
    Node* temp = root;
    Node* succ = NULL;
    while(temp!=NULL) {
        if (temp->key > target->key) {
            succ=temp;
            temp=temp->left;
        }
        else if (temp->key < target->key) {
            temp=temp->right;
        }
        else {
            break;
        }
    }
    return succ;
}

int main() {
    Node* root=NULL;
    vector<int> a = {1,2,3,4,5,6,7};

    root=sortedArrayToBST(a, 0 , a.size()-1);

    printInOrder(root);
    
    cout << endl;
    
    cout << inorderSucc(root,root)->key << endl;


    return 0;
}