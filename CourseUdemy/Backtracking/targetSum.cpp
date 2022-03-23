#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void findTargetSumWaysRec(vector<int> nums, int target, int pos, int sum) {
    if (pos==nums.size()) {
        if (sum==target) {
            cnt++;
        }
        return;
    }

    findTargetSumWaysRec(nums,target,pos+1,sum+nums[pos]);
    findTargetSumWaysRec(nums,target,pos+1,sum-nums[pos]);
}


int findTargetSumWays(vector<int> nums, int target) {
    cnt=0;
    findTargetSumWaysRec(nums,target,0,0);
    return cnt;
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target=3;

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}