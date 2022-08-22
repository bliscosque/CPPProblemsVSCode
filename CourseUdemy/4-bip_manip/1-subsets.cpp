#include <bits/stdc++.h>
using namespace std;

void overLayNumber(vector<char> vc, int number) {
    int j=0;
    while (number > 0) {
        int last_bit=number&1;
        if (last_bit) cout << vc[j];
        j++;
        number=number>>1;
    }
    cout << endl;
}
void generateSubSets(vector<char> vc, int n) {
    for (int i=0;i<(1<<n);i++) {
        overLayNumber(vc, i);
    }
}

int main() {
    vector<char> vc={'a', 'b', 'c'};
    generateSubSets(vc, vc.size());
    return 0;
}