#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int P=5;
int addm(int x, int y) {
    return (x+y)%P;
}

int subm(int x, int y) {
    return ((x-y)%P+P)%P; //o (...+P)%P serve para evitar resposta negativa
}

int mulm(int x, int y) {
    return (x*y)%P; //o (...+P)%P serve para evitar resposta negativa
}

int powr(int x, int y) {
    int res=1;
    while(y) {
        if (y & 1) res=mulm(res,x);
        y/=2;
        x=mulm(x,x);
    }
    return res;
}

int divm(int x, int y) {
    return mulm(x,powr(y,P-2));
}

int32_t main() {
    cout << addm(3,5) << endl;
    cout << (-4%5) << endl; //em c++, isso retorna -4. Mas de acordo com T.N., o resto precisa estar entre [0,p[
    cout << subm(-3,5) << endl;
    cout << mulm(324,234) << endl;
    cout << divm(56,2) << endl;
    return 0;
}