//paragraph
//list of words

//want to check if each of words is present in the readme file

//document="little cute cat loves to code in c++, java & python"
//words={"cute cat", "ttle","cutest", "cat", "quick", "big"}

//yes / yes / no / yes / no / no

//sol
//1 - brute force (for each word)
//2 - suffix trie for document
//3 - suffix trie for words
// com o trie, verificar a partir do document, se encontra no trie | passar pelo document junto com o trie

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;
    Node(char d) {
        data=d;
        isTerminal=false;
    }
};


class Trie{
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    void insert(string word) {
        Node*temp=root;
        for (char ch:word) {
            if(temp->m.count(ch)==0) { //key is not present
                Node *n = new Node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string,bool> &m) {
    Node* temp=t.root;
    for (int j=i;j<document.length();j++) {
        char ch=document[j];
        if (temp->m.count(ch)==0) {
            return;
        }
        temp=temp->m[ch];
        if (temp->isTerminal) {
            string out=document.substr(i,j-i+1); //i ate j
            m[out]=true;
        }
    }
    return;
}

void documentSearch(string document, vector<string> words) {
    //1. create a trie ot words
    Trie t;
    for (auto w:words) {
        t.insert(w);
    }

    //2. searching (Helper Fn)
    unordered_map<string,bool> m;
    for (int i=0;i<document.length();i++) {
        searchHelper(t,document,i,m);
    }

    //3. check which words are marked as True inside Hashmap
    for (auto w: words) {
        if (m[w]) {
            cout << w << ": True" << endl;
        }
        else {
            cout << w << ": False" << endl;
        }
    }
}

int main() {
    string document="little cute cat loves to code in c++, java & python";
    vector<string> words={"cute cat", "ttle","cutest", "cat", "quick", "big"};

    documentSearch(document, words);

    return 0;
}