#include <bits/stdc++.h>
using namespace std;

string A;

void Binary(int n) {
    if (n<1) cout << A << " ";
    else {
        A[n-1]='0';
        Binary(n-1);
        A[n-1]='1';
        Binary(n-1);
    }
}

int main() {
    int n=5;
    A="00000";
    Binary(n);
    return 0;
}