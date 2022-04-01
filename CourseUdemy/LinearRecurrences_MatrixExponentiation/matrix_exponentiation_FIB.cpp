#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mod=1e9+7;
const int sz=2;

struct Mat {
    int m[sz][sz];
    Mat() {
        memset(m,0,sizeof(m));
    }
    void identity() { //matrix with diagonal=1
        for (int i=0;i<sz;i++) {
            m[sz][sz]=1;
        }
    }
    Mat operator* (Mat a) { //overload of *

    }
};

int Fib(int n) {
    Mat r, q;
    r=r * q;
}

int32_t main() {
    int n=5;

    cout << Fib(5) << endl;

    return 0;
}