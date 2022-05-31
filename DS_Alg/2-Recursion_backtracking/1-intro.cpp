//caso base (finalizar recursao) e casos recursivos

//geralmente a solucao iterativa sao mais eficientes que as recursivas (devido overhead de chamada de funcoes)

#include <bits/stdc++.h>
using namespace std;

//fatorial
int fact(int n) {
    if (n<=1) return n;
    else return n*fact(n-1);
}

//print numbers backwards
int print(int n) {
    if (n==0) return 0;
    else {
        cout << n << " ";
        return print(n-1);
    }
}

int main() {
    cout << fact(5) << endl;
    cout << print(5) << endl;
    return 0;
}