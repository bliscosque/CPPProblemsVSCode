#include <bits/stdc++.h>
using namespace std;

bool isPower2(int n) {
    return ((n&(n-1))==0);
}

int main() {
    int n;
    cin >> n;
    cout << isPower2(n) << endl;
    return 0;
}