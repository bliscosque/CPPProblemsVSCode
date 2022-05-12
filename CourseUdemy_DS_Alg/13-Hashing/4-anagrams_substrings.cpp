//two strings are anagrams of each other is the letters of one string can be rearranged to form the other string. -> ex: ab -> ba
//Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

//abba

//4


//substrings are: a, b, b, a, ab, bb, ba, abb, bba, abba
// para estes, os seguintes pares sao validos:
// [a,a]
// [ab,ba]
// [b,b]
// [abb,bba]

//hint: can we check if two strings are anagrams in constant time?
// the idea is hash the strings in a way where hash are the same
// ex: aba -> "21000000000000000000000000" -> 2a, 1b, 0 de outras letras do alfabeto

//hint: can we clyb anagrams with same hash value in buckets for efficient counting?
// create hash and add <hash, freq> in a map
// dependendo da frequencia: freq em C2 -> (freq * (freq-1))/2 (formula da combinacao) 

#include <bits/stdc++.h>
using namespace std;

vector<int> getHashValue(string s, int i, int j) {
    vector<int> freq(26,0);
    //iterate over the orig string from i to j to fill this vector
    for (int k=i;k<=j;k++) {
        char ch=s[k];
        freq[ch-'a']++;
    }
    return freq;
}

int anagrams_substring(string s) {
    map<vector<int>,int> m;
    for (int i=0;i<s.length();i++) {
        for (int j=i;j<s.length();j++) {
            //substring [i..j]
            vector<int> h = getHashValue(s,i,j);
            m[h]++;
        }
    }
    int ans=0;
    for (auto p:m ) {
        int freq=p.second;
        if (freq>=2) {
            ans+=(freq)*(freq-1)/2;
        }
    }
    return ans;
}

int main() {
    cout << anagrams_substring("abba");

    return 0;
}