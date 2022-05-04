//diameter of a tree is maximum distance beween 2 nodes
//case 1 -> diameter passes root (height of left + height of right)
//case 2 -> complete inside left/right subtree (case 1 considerando root como esse nó)

//complexity: O(n^2)

#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data=d;
        left=NULL;
        right=NULL;
    }
};

//Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree() { //preordered build (root, left, right)
    int d;
    cin >> d;
    if (d==-1) {
        return NULL;
    }

    node* n = new node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}

void levelOrderPrint(node*root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        
        node *elem=q.front();
        if (elem==NULL) {
            cout << "\n";
            q.pop();
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << elem->data << " ";
            if (elem->left) {
                q.push(elem->left);
            }
            
            if (elem->right) {
                q.push(elem->right);
            }
        }
    }
    return;
}


//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
node* levelOrderBuild() {
    int d;
    cin >> d;
    node*root = new node(d);

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        int c1,c2;
        cin >> c1 >> c2;
        if (c1!=-1) {
            current->left=new node(c1);
            q.push(current->left);
        }
        if (c2!=-1) {
            current->right=new node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int height(node*root) {
    if (root==NULL) {
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int diameter(node*root) {
   if (root==NULL) {
       return 0;
   } 
   int D1=height(root->left)+height(root->right);
   int D2=diameter(root->left);
   int D3=diameter(root->right);
   return max(D1,max(D2,D3));
}

int main() {
    node*root = levelOrderBuild();
    levelOrderPrint(root);  
    cout << endl << endl << diameter(root) << endl;  

    return 0;
}