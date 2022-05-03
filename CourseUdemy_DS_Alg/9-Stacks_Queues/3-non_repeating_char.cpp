//given continuous stream of char
//output first non-repeating char formed so far, after each new char
//-1 if not exists (0 no EP)

//input={'a','a','b','c','c','b','c','d'};
//output={'a',-1,'b','b','b',-1,-1,'d'};
//a apenas -> a | a a (2x), -1 | b 1x, b | ...

#include <bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    queue<char> q;
    vector<char> v;
    map<char,int> m;
    for (char ch:S) {
        m[ch]++;
        q.push(ch);
        while (m[q.front()]>1) { //remove all duplicate elem
            q.pop();
        }
        if (q.empty()) v.push_back('0');
        else (v.push_back(q.front()));
    }
    return v;
}

int main() {
    string input="aabcbcd"; //a0bbc0d
    vector<char> v=FindFirstNonRepeatingCharacter(input);
    for (auto c:v) {
        cout << c << " ";
    }
    return 0;
}

