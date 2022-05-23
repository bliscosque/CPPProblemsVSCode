#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> exp=heights;
        int count=0;
        sort(exp.begin(),exp.end());
        for (int i=0;i<heights.size();i++) {
            if (exp[i]!=heights[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums1={1,1,4,2,1,3};
    vector<int> nums2={5,1,2,3,4};
    vector<int> nums3={1,2,3,4,5};
    cout << s.heightChecker(nums1) << endl;
    cout << s.heightChecker(nums2) << endl;
    cout << s.heightChecker(nums3) << endl;
    cout << endl;
    return 0;
}