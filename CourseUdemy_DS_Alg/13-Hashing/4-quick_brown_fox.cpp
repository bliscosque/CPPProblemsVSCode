//given a string without spaces, and a list of words. Write a function that finds the "min bars" to be added the string, 
//so that all resulting words are found in the list

//s="thequickbrownfox"
//words={"the", "quickbrown", "fox", "quick", "brown"}

//2 -> the quickbrown fox

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int min_bars_helper(string s, vector<string> words, int idx, unordered_set<string> &m) {
    //base case
    if (s[idx]=='\0') {
        return 0;
    }
    //rec case
    int ans=INT_MAX;
    string current_string="";
    for (int j=idx ; s[j]!='\0' ; j++) {
        current_string+=s[j];
        //check whether prefix is present in set or not
        if (m.find(current_string)!=m.end()) { //find
            int remaing_ans=min_bars_helper(s,words,j+1,m);
            if (remaing_ans!=-1) {
                ans=min(ans,1+remaing_ans);
            }
        }
    }
    if (ans==INT_MAX) return -1;
    else return ans;
}

int min_bars(string s, vector<string> words) {
    unordered_set<string> m;
    for (string w:words) {
        m.insert(w);
    }

    //recursive helper function
    int output=min_bars_helper(s,words,0,m);
    return output-1;
}

int main() {
    cout << min_bars("thequickbrownfox", {"the", "quickbrown", "fox", "quick", "brown"}) << endl;
    return 0;
}