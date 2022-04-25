#include<string>
#include <iostream>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    if (str.length()==0) return "";
    string nstr="";
    char last=str[0];
    int count=1;
    nstr+=str[0];
    for (int i=1;i<str.length();i++) {
        if (str[i]==last) {
            count++;
        }
        else {
            last=str[i];
            nstr+=to_string(count);
            count=1;
            nstr+=str[i];
        }
    }
    nstr+=to_string(count);
    
    if (nstr.length()<str.length())
        return nstr;
    else return str;
}

int main() {
    string input="bbbaaaadeexxxxx";
    cout << compressString(input) << endl;
    input="abc";
    cout << compressString(input) << endl;
    return 0;
}