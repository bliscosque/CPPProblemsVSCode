#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, int c, int x, int y) {
    int dog=x-a;
    if (dog>0) {
        c-=dog;
        if (c<0) return false;
    }
    int cat=y-b;
    if (cat >0) {
        c-=cat;
        if (c<0) return false;
    }
    return true;
        
}

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        
        int a,b,c,x,y;
        cin >> a >> b >> c >> x >> y;
        if (solve(a,b,c,x,y)) cout << "YES" << endl;
        else cout << "NO" << endl;
        

        tc--;
    }
    return 0;
}