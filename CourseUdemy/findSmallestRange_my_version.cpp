#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> nums) {
    int k=nums.size();
    int n_min, n_max, p_min, min_range=INT_MAX, range;
    for (int i=0;i<k;i++) {
        sort(nums[i].begin(),nums[i].end());
    }

    vector<int> ptr(k,0);

    vector<int> ans;
    ans.push_back(INT_MIN);
    ans.push_back(INT_MAX);

    bool flag=true;
    while (flag) {
        n_min=n_max=nums[0][ptr[0]];
        p_min=0;
        for (int i=1;i<k;i++) {
            //cout << p_min << " " << n_min << " " << n_max << " " << endl;
            if (n_min > nums[i][ptr[i]]) {
                n_min=nums[i][ptr[i]];
                p_min=i;
            }
            n_max=max(n_max,nums[i][ptr[i]]);
        }
        range=n_max-n_min;
        if (min_range > range) {
            min_range=range;
            ans[0]=n_min;
            ans[1]=n_max;
        }
        ptr[p_min]++;
        if (ptr[p_min] >= nums[p_min].size()) {
            flag=false;
        }
    }   
    return ans;
}

int main()
{
    //vector<vector<int>> nums = {{ 4, 7, 9, 12, 15 },{ 0, 8, 10, 14, 20 },{ 6, 12, 16, 30, 50 }};
    vector<vector<int>> nums = {{ 4,10,15,24,26 },{ 0,9,12,20 },{5,18,22,30}};
    //vector<vector<int>> nums = {{ 1,2,3 },{ 1,2,3 },{1,2,3}};
 

    vector<int> res=smallestRange(nums);
    for (auto i:res) cout << i <<",";
 
    return 0;
}