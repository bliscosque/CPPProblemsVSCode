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

int max_level = 0;
void leftViewUtil(vector<int>& vec, Node* root, int level)
{
    // base case
    if (root == NULL)
        return;
 
    // If this is the first node of its level
    if (max_level < level) {
        vec.push_back(root->key);
        max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(vec, root->left, level + 1);
    leftViewUtil(vec, root->right, level + 1);
}
 
// Function to get the left view
vector<int> leftView(Node* root)
{
    max_level = 0; // initialise max_level with 0 here
    vector<int> vec;
    // calling util function
    leftViewUtil(vec, root, 1);
    return vec;
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