#include <bits/stdc++.h>
using namespace std;

multimap<string,string> mm;

void letterCombRec(vector<string> &ans, string digits, int i, string strPar) {
    if (i==digits.size()) {
        ans.push_back(strPar);
        //cout << "encontrado: " << strPar << endl;
        return;
    }

    char d=digits[i];
    string digit(1,d);
    //cout << digit << endl;
    auto it1 = mm.equal_range(digit);
    for (auto it = it1.first; it != it1.second; it++) {
        letterCombRec(ans,digits,i+1,strPar+it->second);
    }
}

vector<string> letterCombinations(string digits) {
    
    mm.insert({"2","a"});
    mm.insert({"2","b"});
    mm.insert({"2","c"});
    mm.insert({"3","d"});
    mm.insert({"3","e"});
    mm.insert({"3","f"});
    mm.insert({"4","g"});
    mm.insert({"4","h"});
    mm.insert({"4","i"});
    mm.insert({"5","j"});
    mm.insert({"5","k"});
    mm.insert({"5","l"});
    mm.insert({"6","m"});
    mm.insert({"6","n"});
    mm.insert({"6","o"});
    mm.insert({"7","p"});
    mm.insert({"7","q"});
    mm.insert({"7","r"});
    mm.insert({"7","s"});
    mm.insert({"8","t"});
    mm.insert({"8","u"});
    mm.insert({"8","v"});
    mm.insert({"9","w"});
    mm.insert({"9","x"});
    mm.insert({"9","y"});
    mm.insert({"9","z"});

    vector<string> ans;
    if (digits == "") return ans;
    letterCombRec(ans,digits,0,"");
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    string digits="23";
    vector<string> ans=letterCombinations(digits);
    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}