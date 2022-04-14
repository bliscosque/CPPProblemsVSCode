#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) return a<b;
    
    if (a.length() < b.length())
        return true;
    return false;
}

void subsequence(string s, string o, int i, vector<string> &v) {
    if (i==s.length()) {
        v.push_back(o);
        return;
    }
    subsequence(s,o,i+1,v);
    subsequence(s,o+s[i],i+1,v);
}

int main() {
    string s="abcd";
    vector<string> v;
    string output="";
    subsequence(s,output, 0, v);

    sort(v.begin(),v.end(),comp);

    for (auto a: v) {
        cout << a << ",";
    }
    return 0;
}