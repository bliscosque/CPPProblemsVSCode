//given list n strings
//concatenate all, so that lexigraphical smallest

//input={"c,cb","cba"}
//output="cbacbc"

//input={"a,ab,aba"}
//output="aabaab"

//logica para comparacao no comparator:
//s1 + s2 > s2 + s1

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string x, string y) {
    return x+y < y+x;
} 

int main() {
    vector<string> arr={"a","ab","aba"};
    int n=3;
    
    sort(arr.begin(),arr.end(),compare);
    
    for (auto s:arr) cout << s;
    cout << endl;

    return 0;
}