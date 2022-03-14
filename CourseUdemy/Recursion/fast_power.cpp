#include<bits/stdc++.h>
using namespace std;

//idea behind: a^n = a^((n/2)2), se n for par
//                   a*a^((n/2)2), se n for impar
//dessa maneira, o problema inicial eh dividido sempre ao meio
//O(log(n))

int fast_power(int a , int n) {
    if (n==0) return 1;
    int subProblem=fast_power(a,n/2);
    int subProblemSquare=subProblem*subProblem;
    if (n&1) { //impar
        return a*subProblemSquare;
    }
    return subProblemSquare; //par
}

int main()
{
    cout << fast_power(2,10) << endl;
    return 0;
}