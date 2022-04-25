//split a string in tokens
//1) stringstream
//2) strtok(on char style string)

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