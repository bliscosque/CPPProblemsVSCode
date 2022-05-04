//print tree using level order traversel (level by level)
//need dataStructe -> queue
//NULL na DS significa que o level acabou -> para cada NULL impresso, tem que adicionar um novo NULL, ja que o novo nivel terminou tambem
//queue esta vazia, nao inclui novo NULL (terminou)

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

int main() {
    node*root = levelOrderBuild();
    levelOrderPrint(root);    

    return 0;
}