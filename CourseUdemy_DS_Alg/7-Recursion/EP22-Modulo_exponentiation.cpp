#include<bits/stdc++.h>
using namespace std;

long long int mod=1e9+7;

long long int powerModulo(int a, int b){
    if (a==0) return 0;
    if (b==0) return 1;
    long long int y;

    if (b%2) { //b is odd
        y=a%mod;
        y=(y*powerModulo(a,b-1)%mod)%mod;
    }
    else {
        y=powerModulo(a,b/2);
        y=(y*y)%mod;
    }
    return (y+mod)%mod;
}

int main() {
    cout << powerModulo(5,3) << endl;
    return 0;
}