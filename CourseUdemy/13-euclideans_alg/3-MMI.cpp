//multiplicative module inverse

#include <bits/stdc++.h>
using namespace std;

//retorno: {x,y}

vector<int> extendedGCD(int a,int b){

	if(b==0){
		//return the values of x and y 
		return {1,0,a};
	}
	vector<int> result = extendedGCD(b, a%b);

	// After recursive call is over
	int smallX = result[0];
	int smallY = result[1]; 
	int gcd  = result[2];

	int x = smallY;
	int y = smallX - (a/b)*smallY;

	return {x,y, gcd};
}
int MMI(int a, int m) {
    vector<int> result = extendedGCD(a,m);
    int x=result[0];
    int gcd = result[2];

    if (gcd!=1) {
        cout << "MMI does not exists";
        return -1;
    }
    int ans=(x%m+m)%m; //x can be negative
    return ans;
}

int main() {
    int a, m;
    cin >> a >> m; //should be relatively prime
    //ax+by=gcd(a,b)
    cout << MMI(a,m) << endl;
    return 0;
}