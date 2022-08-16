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

int32_t main() {
    cout << addm(3,5) << endl;
    cout << (-4%5) << endl; //em c++, isso retorna -4. Mas de acordo com T.N., o resto precisa estar entre [0,p[
    cout << subm(-3,5) << endl;
    cout << mulm(324,234) << endl;
    return 0;
}