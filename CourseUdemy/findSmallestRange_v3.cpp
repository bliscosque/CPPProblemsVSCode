#include<bits/stdc++.h>
using namespace std;

//third version - udemy course
//https://github.com/apaarkamal/Coding-Minutes-Competitive-Programming/blob/main/Coding%20Exercise%20Solutions/Find%20K%20Closest%20Elements.cpp

bool mycompare(int a,int b){
    return a>b;
}

vector<int> smallestRange(vector<vector<int>> nums) {
    vector<pair<int,int>>vec;
    vector<int>res;
    int k=nums.size();
    for(int i=0;i<k;i++)
    {
        sort(nums[i].begin(),nums[i].end());
        for(auto itr:nums[i])
        {
            vec.push_back({itr,i});
        }
    }
    sort(vec.begin(),vec.end());
    unordered_map<int,int>cnt;
    int l=0,r=0;
    while(r<vec.size())
    {
        cnt[vec[r].second]++;
        while(cnt.size()==k)
        {
            if(res.empty() || vec[r].first-vec[l].first< res[1]-res[0])
            {
                res={vec[l].first,vec[r].first};
            }
            cnt[vec[l].second]--;
            if(cnt[vec[l].second]==0)
            {
                cnt.erase(vec[l].second);
            }
            l++;
        }
        r++;
    }
    return res;
}

int main()
{
    vector<vector<int>> nums = {{ 4, 7, 9, 12, 15 },{ 0, 8, 10, 14, 20 },{ 6, 12, 16, 30, 50 }};
 
    vector<int> res=smallestRange(nums);
    for (auto i:res) cout << i <<",";
 
    return 0;
}