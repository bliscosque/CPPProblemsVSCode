//unnecessary or multiple parenthesis
//input="((a+b))" -> yes
//input="(a+(b)/c)" ->yes
//input="(a+b*(c-d))" -> no (all are necessary)

//no final, é redundante quando tem () sem ter operadores dentro deles
//sol: stack -> fazendo push dos operands & operators

#include <bits/stdc++.h>
using namespace std;

bool checkRedundant(string str) {
    stack<char> s;
    for (char ch:str) {
        if (ch!=')') {
            s.push(ch);
        }
        else { //find )
            bool op_found=false;
            while (!s.empty() and s.top()!='(') {
                char top=s.top();
                if (top=='+' || top=='-' || top=='*' || top=='/') {
                    op_found=true;
                }
                s.pop();
            }
            s.pop(); //pop ( after loop
            if (op_found==false) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string str="((a+b))";
    cout << checkRedundant(str) << endl;
    str="(a+(b)/c)";
    cout << checkRedundant(str) << endl;
    str="(a+b*(c-d))";
    cout << checkRedundant(str) << endl;

    return 0;
}