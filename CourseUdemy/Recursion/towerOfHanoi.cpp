#include<bits/stdc++.h>
using namespace std;

int cnt=0;
void TowerOfHanoi(int n, char from, char helper, char to) {
    if (n==0) return;

    //cout << n << " " << from << " " << helper << " " << to << endl;
    TowerOfHanoi(n-1, from, to, helper);

    //move latest disc
    cout << from << " -> " << to << endl;
    cnt++;

    TowerOfHanoi(n-1, helper, from, to);
}

int main() {

    int n;
    cin >> n;

    TowerOfHanoi(n,'A','B','C');

    cout << "num mov: " << cnt << endl;
    return 0;
}