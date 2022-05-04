#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> vi={0,1};
        int i=2;
        while(i<=n) {
            vi.push_back(vi[i-1]+vi[i-2]);
            i++;
        }
        return vi[n];
    }
};

int main() {
    Solution s;
    cout << s.fib(2) << endl;
    cout << s.fib(3) << endl;
    cout << s.fib(4) << endl;
    
}