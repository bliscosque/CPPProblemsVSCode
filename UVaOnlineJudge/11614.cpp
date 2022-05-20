#include <bits/stdc++.h>
using namespace std;

//Get-Content .\11614.in |.\11614.exe

//é uma PA... Sn=(a1+an)/2*n

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int n;
        cin >> n;
        if (n==0) cout << 0 << endl;
        else {
            double sqr=sqrt(1+8*n);
            int res=(-1+ceil(sqrt(1+8*n)))/2;
            cout << res << endl;
        }
        tc--;
    }

    return 0;
}

//wrong answer