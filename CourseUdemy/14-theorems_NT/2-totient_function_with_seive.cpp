#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N=1e5;

// complexidade: n*loglog(n)
void calculate_totient() {
    //construindo o crivo
    vector<bool> pr(N,true);
    vector<int> tot(N);
    for (int i=2;i<N;i++) {
        for (int j=i*i;j<N;j+=i) {
            pr[j]=false;
        }
    }

    iota(tot.begin(), tot.end(),0); // tot[0]=0, tot[1]=1, ...
    for (int i = 2; i < N; i++) {
        if (pr[i]) { //se numero for primo
            for (int j = i; j < N; j+=i) {
                // j is divisible by i
                tot[j] /= i;
                tot[j] *= (i-1);
            }
        }
    }
    
    for (int i = 1; i < 10; i++)
    {
        cout << i << " " << tot[i] << endl;
    }
    
}

int32_t main() {
    calculate_totient();

    return 0;
}