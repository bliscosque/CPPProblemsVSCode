//given a list words
//given MxN board where every cell has one character
//find all possible words that are part of the list and can be formed by a seq of adj char from the board.
//Can move 8 positions but cannot reuse the cell

//8-way DFS search for every cell
//trie will guide & control the search

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

#define M 3
#define N 4


class Node{
public:
    char s;
    unordered_map<char,Node*> children;
    string word; //complete word that is formed
    bool isTerminal;
    Node(char s) {
        this->s=s;
        isTerminal=false;
        word="";
    }
};


class Trie{
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    void addWord(string word) {
        Node*temp=root;
        for (char ch:word) {
            if(temp->children.count(ch)==0) { //key is not present
                Node *n = new Node(ch);
                temp->children[ch]=n;
            }
            temp=temp->children[ch];
        }
        temp->isTerminal=true;
        temp->word=word; //entire word
    }


};


//main alg (8-way DFS + trie guided search)
void dfs(vector<vector<char>> board, Node *node, int i, int j, bool visited[M][N], unordered_set<string> &output) {
    //base case
    char ch=board[i][j];
    if (node->children.count(ch)==0) return;
    
    //otherwise trie contains this node
    visited[i][j]=true;
    node=node->children[ch];

    //if it is a terminal node 
    if (node->isTerminal) {
        output.insert(node->word);
    }
    //explore the nbrs
    vector<int> dx={0,1,1,1,0,-1,-1,-1};
    vector<int> dy={-1,-1,0,1,1,1,0,-1};
    
    for (int k=0;k<8;k++) {
        int newI=i+dx[k];
        int newJ=j+dy[k];
        if (newI >=0 && newJ>=0 && newI < M && newJ < N && !visited[newI][newJ]) {
            dfs(board,node,newI,newJ,visited,output);
        }
    }

    //backtracking
    visited[i][j]=false;
}

int main() {
    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"}; 
    vector<vector<char>> board = {{'S', 'E', 'R', 'T'},
                                {'U', 'N', 'K', 'S'},
                                {'T', 'C', 'A', 'T'}};

    //1. Trie
    Trie t;
    for (auto w:words) {
        t.addWord(w);
    }

    //2. Container to store all found words
    unordered_set<string> output; // uma palavra pode ser formada de mais de uma maneira. O Set é para evitar duplicados

    //3. 8-way DFS search from every cell
    bool visited[M][N] = {0};
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            dfs(board,t.root,i,j, visited,output);
            //reset the visited array (while backtracking)

        }
    }

    //4. Print the output
    for (auto word:output) {
        cout << word << endl;
    }

    return 0;
}