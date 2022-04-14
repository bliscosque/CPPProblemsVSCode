//is second string subsequence of first one?
#include <iostream>
#include <string>
using namespace std;

bool isSubset(string a, string b) {
    if (a.find(b) != string::npos) return true;
    return false;
}

int main() {
    string a="This is a big one";
    string b="big";
    cout << isSubset(a,b) << endl;
    cout << isSubset(a,"small") << endl;
    return 0;
}