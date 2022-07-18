#include <bits/stdc++.h>
using namespace std;

int count_bits(int n) {
    int ans=0;
    while (n>0) {
        n=n&(n-1); //unset last bit
        ans++; //there was one set bit, increase ans
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << count_bits(n) << endl;
    return 0;
}