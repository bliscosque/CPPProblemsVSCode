#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/shortest-superstring-problem/

//Let arr[] be given set of strings.
//1) Create an auxiliary array of strings, temp[].  Copy contents
//   of arr[] to temp[]
// 2) While temp[] contains more than one strings
//      a) Find the most overlapping string pair in temp[]. Let this
//         pair be 'a' and 'b'. 
//      b) Replace 'a' and 'b' with the string obtained after combining
//         them.
// 3) The only string left in temp[] is the result, return it.

int findOverlappingPair(string s1, string s2, string &res) {
    int max=INT_MIN; //overlap value
    int len1=s1.length();
    int len2=s2.length();

    //check if suffix of s1 matheches prefix of s2
    for (int i=1;i<=min(len1,len2);i++) {
        //compare (last i char in s1) with (first i char in str2) 
        if (s1.compare(len1-i,i,s2,0,i)==0) {
            if (max < i) {
                //update max and str
                max=i;
                res=s1+s2.substr(i);
            }
        }
    }

    //check reversed (prefix of s1 matches suffix of s2)
        for (int i=1;i<=min(len1,len2);i++) {
        //compare (FIRST i char in s1) with (LAST i char in str2) 
        if (s1.compare(0,i,s2,len2-i,i)==0) {
            if (max < i) {
                //update max and str
                max=i;
                res=s2+s1.substr(i);
            }
        }
    }
    return max;

}

string shortestSuperstring(vector<string> words) {
    int n=words.size();
    //n-1 times (consider every pair)
    while(n!=1) {
        int max=INT_MIN; //maximum overlap
        int l,r; //index of strings
        string resStr; //involved in maximum overlap

        //maximum overlap
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                string str;

                //res = max lenght of matching prefix/suffix --- in both directions 
                //str  & (reference) = result of overlap 
                int res=findOverlappingPair(words[i],words[j],str);

                //check max overlap
                if (max < res) {
                    max=res;
                    resStr.assign(str);
                    l=i,r=j;
                }
            }
        } 
        //ignoring last elem in next cycle
        n--;

        //if no overlap, append words[n] to words[0]
        if (max==INT_MIN)
            words[0]+=words[n];
        else {
            //copy resultant str to index l
            words[l]=resStr;
            //copy string at last index to index r
            words[r]=words[n];
        }
    }
    return words[0];
}

int main() {
    vector<string> words = {"catg", "ctaag", "gcta", "ttca", "atgcatc"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}