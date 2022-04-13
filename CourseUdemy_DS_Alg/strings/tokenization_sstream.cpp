//split a string in tokens
//1) Stringstream
//2) 

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    getline(cin,input);

    stringstream ss(input);

    //support >> and << operators
    string token;
    vector<string> tokens;
    while (getline(ss,token, ' ')) {
        tokens.push_back(token);
    }

    for (auto s:tokens) {
        cout << s << endl;
    }

    return 0;
}