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

int main() {
    Node* root=NULL;
    vector<int> a = {8,3,10,1,6,14,4,7,13};

    for (int x:a) {
        //cout << x << endl;
        root=insert(root,x);
    }
    printInOrder(root);

    return 0;
}