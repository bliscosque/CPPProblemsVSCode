#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int note;
        cin >> note;
        if (note >= 1900) cout << "Division 1" << endl;
        else if (note >= 1600 && note <=1899) cout << "Division 2" << endl;
        else if (note >= 1400 && note <=1599) cout << "Division 3" << endl;
        else if (note  <=1399) cout << "Division 4" << endl;
        tc--;
    }
    return 0;
}