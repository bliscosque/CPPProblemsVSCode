#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

/*
string parseword(string word) {
    string ret="";
    ret+=toupper(word[0]);

    for (int i=1;i<word.length();i++) {
        ret+=tolower(word[i]);
    }
    return ret;
}
*/

string normalize(const string &sentence) {

    /*vs1
    stringstream ss(sentence);

    //support >> and << operators
    string token;
    string res = "";
    //issue with multiples whitespaces
    while (getline(ss,token, ' ')) {
        res+=parseword(token) + " ";
    }
    res=res.substr(0,res.length()-1);
    return res;

    */
   bool isUpper=1;
   string res;
   for (char c:sentence) {
       if (c==' ') {
           isUpper=true;
           res+=c;
       }
       else if (isUpper) {
           res+=toupper(c);
           isUpper=false;
       }
       else {
           res+=tolower(c);
       }
   } 
   return res;
}

int main() {
    string s1="this is SO FUN!";
    cout << normalize(s1) << endl;
    cout << normalize("a") << endl;

    return 0;
}