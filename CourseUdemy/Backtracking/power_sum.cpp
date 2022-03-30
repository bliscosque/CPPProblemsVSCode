#include<bits/stdc++.h>
using namespace std;


bool test(vector<int> &vi, int x, int n) {
    int sum=0;

    cout << endl;
    return sum==x;
}

int generate(int x, int n, vector<int> &vi) {
    int sum=0;
    int ans=0; 

    for (auto i: vi) {
        sum+=pow(i,n);
    }
    if (sum==x) return 1;
    else {
        int answer=0;
        int v=vi.empty()?1:vi.back()+1;
        while (sum+pow(v,n) <= x) {
            vi.push_back(v);
            answer+=generate(x,n,vi);
            vi.pop_back();
            v++;
        }
        return answer;
    }
}

int solve(int x,int n){
    vector<int> vi;

    return generate(x,n,vi);

}

int main() {
    cout << solve(13,2) << endl;
    cout << solve(100,2) << endl;
    return 0;
}