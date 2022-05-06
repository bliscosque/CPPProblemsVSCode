#include<bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


vector<int> ans;

void printNodeK(node *root, int k) {
    if (root==NULL) {
        return;
    }
    else if (k==0) {
        ans.push_back(root->data);
        return;
    }
    else {
        printNodeK(root->left,k-1);
        printNodeK(root->right,k-1);
    }
}

int printNodesAtDistanceK(node* root, node* target, int k) { //retorna distancia
    //base case
    if (root==NULL) {
        return -1;
    }

    //reach target node
    if (root==target) {
        printNodeK(target,k);
        return 0;
    }

    //
    int distLeft = printNodesAtDistanceK(root->left, target, k);
    if (distLeft!=-1) {
        //2 cases
        //print the current node
        if (distLeft+1==k) {
            ans.push_back(root->data);
        }
        //or print some nodes in the right subtree
        else {
            printNodeK(root->right,k-2-distLeft);
        }
        return 1+distLeft;
    }

    int distRight = printNodesAtDistanceK(root->right, target, k);
    if (distRight!=-1) {
        //2 cases
        //print the current node
        if (distRight+1==k) {
            ans.push_back(root->data);
        }
        //or print some nodes in the right subtree
        else {
            printNodeK(root->left,k-2-distRight);
        }
        return 1+distRight;
    }
    return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k){
    ans.clear();
    printNodesAtDistanceK(root,target,k);
    sort(ans.begin(),ans.end());
    return ans;
}