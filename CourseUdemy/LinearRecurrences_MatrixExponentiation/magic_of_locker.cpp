#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//https://palak001.medium.com/spoj-locker-magic-of-the-locker-a758bccf432f

ll mod=1e9+7;

ll binPow(ll a, ll n) {
    if (n==0) return 1;
    if (n==1) return a%mod;
    ll r=binPow(a,n/2);
    if (n%2 == 0)
        return (r%mod * r%mod)%mod;
    else return  (r%mod * r%mod * a%mod)%mod;
}

int locker (int n) {
    if (n <=2) return n;
    ll n1, ans;
    // se o restante for 1, nao havera sentido multiplicar por 1 ao final
    if (n%3==1) {
        n1=(n-4)/3;
        ans=4*binPow(3,n1);
    }
    //se sobrar 2, multiplica por 2 ao final
    else if (n%3==2) {
        n1=(n-2)/3;
        ans=2*binPow(3,n1);
    }
    else
        ans=binPow(3,n/3);
    ans=ans%mod;
    return ans;
}

int main() {
    cout << locker(10) << endl;
    return 0;
}