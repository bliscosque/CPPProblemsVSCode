#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containEven(int num) {
        //cout << "num: " << num << endl;
        if(num==0) return 1;
        int cnt=0;
        while(num>0) {
            cnt++;
            num/=10;
        }
        //cout << "cnt: " << cnt << endl;
        return (cnt%2==0);
    }
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for (int num:nums) {
            if (containEven(num)) cnt++;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    vector<int> v1={12,345,2,6,7896};
    cout << s.findNumbers(v1) << endl;
    
    vector<int> v2={555,901,482,1771};
    cout << s.findNumbers(v2) << endl;
    
    return 0;
}