#include <bits/stdc++.h>
using namespace std;

int fastExp(int a, long long n, int P) { // P=MOD
    //cout << a << " " << n << endl;
    if (n==0) return 1;
    if (n%2==0) //n é par
        return fastExp((1LL*a*a)%P,n/2,P);
    return (1LL*a*fastExp(a,n-1,P))%P;
}

int main() {
    cout << fastExp(2,10,1e9+7) << endl;
    return 0;
}