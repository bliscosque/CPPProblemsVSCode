//given 2 str, find number of times second string occurs as a subseq in the first str
//s1="ABCDCE"
//s2="ABC"
//2

#include <bits/stdc++.h>
using namespace std;

//Recursive code
int countSub(string a, string b, int m, int n) {
    if ((m==-1 && n==-1) || n==-1)  return 1; //find one possibility
    if (m==-1) return 0; // nao encontrou uma opcao

    if (a[m]==b[n]) { //ultimo char matches
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n); //including char and not including it
    }
    else { //nao eh igual
        return countSub(a,b,m-1,n);
    }

}


int main() {
    string a="ABCECDG";
    string b="ABC";

    cout << countSub(a,b,a.size()-1,b.size()-1) << endl;

    return 0;
}