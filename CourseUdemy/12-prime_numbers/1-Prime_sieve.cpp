#include <bits/stdc++.h>
using namespace std;

void prime(vector<int> &sieve, int n) {
    for (int i=2;i<=n;i++) {
        for (int j=2*i;j<=n;j+=i) {
            sieve[j]=i;
        }
    }
    for (int i=0;i<=n;i++) {
        cout << i << " " << sieve[i] << endl;
    }
}

void primeSieve (vector<int> &sieve, int n) {
    sieve[0]=sieve[1]=0; //not primes
    for (int i=2;i<=n;i++) {
        if (sieve[i]) { // se o numero atual for primo
            for (int j=i*i;j<=n;j+=i) { // os numeros menores que i*i já foram marcados... é uma otimizacao
                sieve[j]=0;
            }
        }
    }
    for (int i=0;i<=n;i++) {
        cout << i << " " << sieve[i] << endl;
    }
}

int main() {
    int n=20;
    vector<int> sieve(n+1,0);

    // prime(sieve,n);

    vector<int> sieve2(n+1, 1);

    primeSieve(sieve2, n);

    return 0;
}