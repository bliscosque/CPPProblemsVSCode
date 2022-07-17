#include <bits/stdc++.h>
using namespace std;

void convBin(int num) {
    for (int i=31;i>=0;i--) {
        if (num&(1<<i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

int main() {
    int num=10;
    convBin(num);
    cout << ~0 << endl;
    return 0;
}