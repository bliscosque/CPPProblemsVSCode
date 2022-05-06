//find the largest sum of a subset of nodes in a binary tree,
//such that if a node is included in the sum then its parent and children must not be included in the subset sum.

//    1
//  2   3
// 4 5    6
//    7
//Se escolhe 5, pode somar 1,4,5,6 (nao inclui filhos e pais de cada nó)
//7+4+6+1=18 --> maximo para esse exemplo
//recursao com inclui nó na soma, exclui nó da soma

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

class HDPair{
public:
    int height;
    int diameter;
};

HDPair optDiameter(node*root) {
    HDPair p;
    if (root==NULL) {
        p.height=p.diameter=0;
        return p;
    }
    //otherwise
    HDPair Left=optDiameter(root->left);
    HDPair Right=optDiameter(root->right);
    p.height=max(Left.height,Right.height)+1;

    int D1=Left.height+Right.height;
    int D2=Left.diameter;
    int D3=Right.diameter;

    p.diameter=max(D1,max(D2,D3));
    return p;
}

int replaceSum(node* root) {
    if (root==NULL) {
        return 0;
    }
    if (root->left==NULL && root->right==NULL ) {
        return root->data;
    }
    int tmp=root->data;
    int sumRight=replaceSum(root->right);
    int sumLeft=replaceSum(root->left);
    root->data=sumRight+sumLeft; //update with sum 
    return sumRight+sumLeft+tmp; //return sum total
}

pair<int,bool> isHeightBalanced(node* root) {
    pair<int,bool> pil, Left, Right;
    if (root==NULL) {
        pil.first=0;
        pil.second=true;
        return pil;
    }
    Left=isHeightBalanced(root->left);
    Right=isHeightBalanced(root->right);

    pil.first=(Left.first,Right.first)+1;
    if (abs(Left.first-Right.first)<=1 && Left.second && Right.second) {
        pil.second=true;
    }
    else pil.second=false;

    return pil;
}

class Pair{
public:
    int inc;
    int exc;
};

Pair maxSubsetSum(node* root) {
    Pair p;
    if (root==NULL) {
        p.inc=p.exc=0;
        return p;
    }
    Pair Left = maxSubsetSum(root->left);
    Pair Right = maxSubsetSum(root->right);

    p.inc=root->data+Left.exc+Right.exc;
    p.exc=max(Left.inc, Left.exc)+max(Right.inc,Right.exc);
    return p;
}

int main() {
    node*root = levelOrderBuild();
    levelOrderPrint(root); 
     
    Pair p = maxSubsetSum(root);
    cout << max(p.inc,p.exc) << endl;  

    return 0;
}