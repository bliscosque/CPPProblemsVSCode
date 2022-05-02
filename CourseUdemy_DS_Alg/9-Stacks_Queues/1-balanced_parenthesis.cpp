//is the pair of parenthesis valid?
//input="((a+b)*x-d)"
//true

//input="((a+b]+c)*(d-e)"
//false
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string input) {
    stack<char> s;
    for (auto ch:input) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                s.push(ch);
                break;
            case ')':
                if (!s.empty() && s.top()=='(') {
                    s.pop();
                }
                else {
                    return false;
                }
                break;
            case ']':
                if (!s.empty() && s.top()=='[') {
                    s.pop();
                }
                else {
                    return false;
                }
                break;
            case '}':
                if (!s.empty() && s.top()=='{') {
                    s.pop();
                }
                else {
                    return false;
                }
                break;
            default: continue;
        }
    }
    if (s.empty()) return true;
    return false;
}

int main() {
    string s="((a+b]+c)*(d-e)";
    if (isBalanced(s)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}