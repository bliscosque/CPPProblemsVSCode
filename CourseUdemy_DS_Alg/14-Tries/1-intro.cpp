//important DS for Pattern Matching Problems
//given a list of strings and Q Que each query containing a word, you have to tell whether the word is contained in the list or not.

//words={"apple", "ape", "mango", "news", "no"}
//queries={"apple", "banana", "new", "mango"}

//yes, no, no, yes

//1-brute force
//2-insert DS (e.g.: BST)
//3-unorderedSet (hashing)
//4-tries search: (O(w) -> tamanho da palavra) / Insert O(w)

//what is a trie? --- a.k.a. prefix tree
//1- generic tree like DS
//2- efficient retrieval DS
//3- uses extra storage
//operations: insert/search
//cada no contem uma letra
//marcar a ultima letra da palavra

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
    bool search(string word) {
        Node *temp=root;
        for (char ch:word) {
            if (temp->m.count(ch)==0) return false;
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main() {
    vector<string> words={"apple", "ape", "mango", "news", "no"};
    Trie t;
    for (auto w:words) {
        t.insert(w);
    }

    cout << t.search("apple") << endl;
    cout << t.search("appl") << endl;

    return 0;
}