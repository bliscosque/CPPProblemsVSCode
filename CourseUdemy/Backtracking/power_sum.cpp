#include<bits/stdc++.h>
using namespace std;

int ans=0;

bool test(vector<int> &vi, int x, int n) {
    int sum=0;
    for (auto i: vi) {
        cout << "i: " << i << endl;
        sum+=pow(i,n);
    }
    cout << endl;
    return sum==x;
}

void generate(int x, int n, vector<int> &vi, int amt, int max, int last) {
    if (vi.size() == amt) {
        if (test(vi,x,n)) ans++;
        return;
    }
    for (int j=last;j<=max;j++) {
        generate(x,n,vi,amt,max,last+1);
        vi.push_back(j);
        generate(x,n,vi,amt,max,last+1);
        vi.pop_back();
    }
}

int solve(int x,int n){
    vector<int> vi;
    int max=pow(x,1.0/n)+1;
    //for (int i=1;i<=max;i++) {
    //    generate(x,n,vi,i, max,1);
    //}
    generate(x,n,vi,1, max,1);
    return ans;
}

int main() {
    cout << solve(13,2) << endl;
    //cout << solve(100,2) << endl;
    return 0;
}