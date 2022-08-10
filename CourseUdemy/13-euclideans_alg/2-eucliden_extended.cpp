#include <bits/stdc++.h>
using namespace std;

//retorno: {x,y}
vector<int> extendedGCD(int a, int b) {
    //base case
    if (b==0) {
        return {1,0}; //ax+0y=gcd(a,0) -> x=a/a=1
    }
    vector<int> result=extendedGCD(b,a%b);
    int x1=result[0];
    int y1=result[1];

    int x=y1;
    int y=x1-(a/b)*y1;
    return {x,y};

}

int main() {
    int a, b;
    cin >> a >> b;
    //ax+by=gcd(a,b)
    cout << extendedGCD(a,b)[0] << " " <<  extendedGCD(a,b)[1] << endl;
    return 0;
}