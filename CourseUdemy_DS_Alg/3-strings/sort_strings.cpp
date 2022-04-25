//given a list of n strings
//strings consists of digits and spaces
//no. of spaces equal in n strings
//variation of sort command
//no space in begin, end, no consecutive spaces
//key: column to be used as sorted
//reversed: true or false
//comparison-type: lexigraphical or numeric

//logic:
//1) extract keys from every string (tokenization) pair<string, key)
//2) sorting, 2 comparators: lexicographical or numerical
//3) reverse 

/*sample 
input
3
92 022
82 12
77 13
2 false numeric
----
output
82 12
77 13
92 022
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

string extractStringAtKey(string str,int key) {
    stringstream ss(str);

    string token;
    while (key>1) {
        getline(ss,token, ' ');
        key--;
    }
    return token;
}

int convertToInt(string s) {
    int ans=0;
    int p=1;

    for (int i=s.length()-1;i>=0;i--) {
        ans+= ((s[i-'0'])*p);
        p*=10;
    }
    return ans;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2) {
    string k1, k2;
    k1=s1.second;
    k2=s2.second;

    return convertToInt(k1) < convertToInt(k2);
}

bool lexicoCompare(pair<string,string> s1, pair<string,string> s2) {
    string k1, k2;
    k1=s1.second;
    k2=s2.second;

    return k1 < k2;
}

int main() {
    int n;
    cin >> n;

    cin.get(); //consume the \n

    string temp;
    vector<string> v;

    for(int i=0;i<n;i++) {
        getline(cin,temp);   //include white spaces
        v.push_back(temp);
    }

    int key;
    string reversal,ordering;
    cin >>key>>reversal >>ordering; //does not include white spaces

    // for (auto a:v) {
    //     cout << "V: " << a << endl;
    // }
    // cout << endl;
    
    //1. extract keys
    vector<pair<string,string>> vp;

    for (int i=0;i<n;i++) {
        cout << "vi: " << v[i] << endl;
        vp.push_back({v[i],extractStringAtKey(v[i],key)});
        cout << vp[i].first << endl;
    }

        
    for (auto a:vp) {
        cout << "V1: " << a.first << " - " << a.second << endl;
    }
    cout << endl;

    //2. sorting
    if (ordering=="numeric") {
        sort(vp.begin(),vp.end(),numericCompare);
    }
    else {
        sort(vp.begin(),vp.end(),lexicoCompare);
    }

    //3. reversal
    if (reversal=="true") {
        reverse(vp.begin(),vp.end());
    }

    //4. output
    for(int i=0;i<n;i++) {
        cout << vp[i].first << endl;
    }
    return 0;
}