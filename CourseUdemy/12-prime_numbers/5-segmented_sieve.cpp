// o algoritmo de sieve normal pode necessitar de muita memória

// criar um sieve com todos os primos até sqrt(n) -> 10^5
// agora computar o crivo para m...n

#include <bits/stdc++.h>
using namespace std;

#define N 100000
int sieveArr[N+1] = {0};
vector<int> primes;

void sieve() {
    for (long long i=2;i<=N;i++) {
        if (sieveArr[i]==0) {
            primes.push_back(i);
            //mark multiples as non-prime
            for (long long j=i*i;j<=N;j+=i) {
                sieveArr[j]=1; // non-prime
            }
        }
    }
}



int main() {
    // precompute
    sieve();

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >>n;
        vector<int> segment(n-m+1,0);
        for (auto p:primes) {
            // stop when p^2 > n
            if (p*p > n) break;
            int start=(m/p)*p;
            if (p>=m && p<=n) start=2*p; // special case
            for (int j=start;j<=n;j+=p) {
                if (j<m) continue; // if idx does not exist
                segment[j-m] = 1; // not prime
            }
        }
        //primes are stored as 0
        for (int i=m;i<=n;i++) {
            if (segment[i-m]==0 && i!=1) {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}