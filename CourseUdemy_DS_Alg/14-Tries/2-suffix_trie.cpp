//stores all the sufixes of a given string
//hello -> hello ello llo lo o -> inserir todos os sufixos dentro da trie


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

class SuffixTrie{
public:
    Node* root;
    SuffixTrie() {
        root=new Node('\0');
    }
    void insert_helper(string word) {
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

    void insert(string word) {
        for (int i=0;word[i]!='\0';i++) {
            insert_helper(word.substr(i));
        }

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
    vector<string> words={"hello"};
    SuffixTrie t;
    for (auto w:words) {
        t.insert(w);
    }

    cout << t.search("ello") << endl;
    cout << t.search("o") << endl;
    cout << t.search("other") << endl;


    return 0;
}