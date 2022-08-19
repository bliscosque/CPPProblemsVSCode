#include <bits/stdc++.h>
using namespace std;

const int Nmax=100001;
int fr[Nmax];

void findNumber(int n) {
	int cur_rem=0;
	for (int i=1;i<=n;i++) {
		cur_rem=(cur_rem*10+1)%n; //1, 11, 111, ... % n
		if (cur_rem==0) { //se o resto for 0, imprime o numero
			for(int j=1;j<=i;j++) {
				cout << 1;
			}
			return;
		}
		if (fr[cur_rem]!=0) { // se 2 numeros tem o mesmo resto, imprime a diferença dos 2
			for (int j=1;j<=i-fr[cur_rem];j++) {
				cout << 1;
			}
			for (int j=1;j<=fr[cur_rem];j++) {
				cout << 0;
			}
			return;
		}
		fr[cur_rem]=i;
	}
}


int main() {
	int n;
	cin >> n;
	findNumber(n);
	return 0;
}
