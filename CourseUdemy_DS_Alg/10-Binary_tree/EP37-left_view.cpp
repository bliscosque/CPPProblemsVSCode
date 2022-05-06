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

vector<int> v;

void leftView2(Node * root){
    if (root==NULL) {
        return;
    }
    else if (root->left && root->right) { //node has 2 children, go to left
        v.push_back(root->key);
        leftView2(root->left);
        return;
    } 
    else if (root->left) {
        v.push_back(root->key);
        leftView2(root->left);
        return;
    }
    else { //has only right... go there
        v.push_back(root->key);
        leftView2(root->right);
        return;
    }
}

vector<int> leftView(Node * root){
    v.clear();
    leftView2(root);
    return v;
    
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->right = new Node(4);
	root->right->right = new Node(6);

	root->left->right->right = new Node(5);

    vector<int> vi= leftView(root);
    for (auto i:vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}