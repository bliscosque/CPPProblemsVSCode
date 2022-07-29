#include <bits/stdc++.h>
using namespace std;


void factorise(int n) {
    for (int i=2;i*i<=n;i++){ // precisa ir apenas até sqrt(n)
        if (n%i==0) {
            while (n%i==0) {
                cout << i << endl;
                n/=i;
            }
        }
        if (n==1) return;
    }
    if (n!=1) { // n é primo
        cout << n << endl;
    }
}

int main() {
    factorise(7);
    return 0;
}