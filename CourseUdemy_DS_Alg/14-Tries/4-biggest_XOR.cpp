//given an array, find the maximum XOR that you can form by picking two numers from the array
//input={3,10,5,8,2,25};

//output=28 -> XOR of 5 and 25 = 28

//1 - brute force O(n^2)
//2 - using tries

//in binary, the ones that contribute more are the ones that have more number of 1s in the left part 
//3  - 00011
//10 - 01010
//5  - 00101
//25 - 11001
//8  - 01000
//2  - 00010

#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    node *left; //0
    node *right;//1
};

class trie{
    node*root;
public:
    trie() {
        root=new node();
    }
    void insert(int n) {
        node* temp=root;
        for (int i=31;i>=0;i--) {
            int bit = (n>>i) & 1;
            if (bit==0) {
                if (temp->left==NULL) {
                    temp->left=new node();
                }
                temp=temp->left;
            }
            else {
                if (temp->right==NULL) {
                    temp->right=new node();
                }
                temp=temp->right;
            }
        }
    }

    int max_xor_helper(int value) {
        int current_ans=0;
        node* temp=root;
        for (int j=31;j>=0;j--) {
            int bit = (value>>j)&1;
            if (bit==0) {
                if (temp->right!=NULL) {
                    temp=temp->right;
                    current_ans+=(1<<j);
                }
                else {
                    temp=temp->left;
                }
            }
            else {
                if (temp->left!=NULL) {
                    temp=temp->left;
                    current_ans+=(1<<j);
                }
                else {
                    temp=temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(vector<int> input, int n) {
        int max_xor=0;
        for (int i=0;i<n;i++) {
            int value=input[i];
            insert(value);
            int current_xor=max_xor_helper(value);
            max_xor=max(max_xor,current_xor);
        }
        return max_xor;
    }
};

int main() {
    vector<int> input={3,10,5,25,9,2};
    int n=input.size();
    trie t;
    cout << t.max_xor(input,n) << endl;
}