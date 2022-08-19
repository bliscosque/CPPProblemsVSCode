#include <bits/stdc++.h>
using namespace std;

// recursive
int fastExp(int a, long long n, int P) { // P=MOD
    //cout << a << " " << n << endl;
    if (n==0) return 1;
    if (n%2==0) //n é par
        return fastExp((1LL*a*a)%P,n/2,P);
    return (1LL*a*fastExp(a,n-1,P))%P;
}

//iterative
int fastExpIterativo(int a, long long n, int P) {
	int ans=1;
    while(n>=1) {
	    if (n%2==0) { //n é par
		    a=(1LL*a*a) %P;
		    n /= 2;
	    }
	    else {
		    ans=(1LL*ans*a)%P;
		    n--;
	    }
    }
    return ans;
}

int main() {
    cout << fastExp(2,10,1e9+7) << endl;
    cout << fastExpIterativo(2,10,1e9+7) << endl;
    return 0;
}
