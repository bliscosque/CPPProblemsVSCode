#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    unordered_map<char,int> um;
    for (auto c:input) {
        um[c]++;
        if (um[c]>1) return c;
    }
    
    return '\0';
}

int main() {
    cout << firstRepeatChar("codingminutes");
    return 0;
}