//WA

#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    if (s.size()==1) return 1;
    //find last 1
    auto l1=s.find_last_of('1');
    auto l0=s.find_first_of('0');
    if (l1 != string::npos && l0!=string::npos) {
        return l0-l1+1;
    }
    if (l1==string::npos && l0==string::npos) {//contains only ?
        return s.size();
    }
    auto li=s.find('?');
    if (li==string::npos) { //does not contain ?
        return 1;
    }
    if (l0 != string::npos) { //contains  0 and ?
        if (s[0]=='0') return 1;
        else {
            int sum=1;
            if (s[l0-1]=='?') sum++;
            if (l0<s.size()-1) {
                if (s[l0+1]=='?') sum++;
            }
            return sum; 
        }
    
    }
    if (l1 != string::npos) { //contains  1 and ?
        return 1;
    }
    return -1;
}

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        
        string s;
        cin >> s;
        cout << solve(s) << endl;        

        tc--;
    }
    return 0;
}