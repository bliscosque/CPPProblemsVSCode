#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;



int cntSubarrays(vector<int> arr,int k){
    int cnt=0;
    int n=arr.size();
    unordered_map<int, int> um;
    int currsum=0;
    
    for(int i=0;i<n;i++) {
        currsum+=arr[i];
        
        if (currsum==k) cnt++;

        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if(um.find(currsum-k) !=um.end())
            cnt+=(um[currsum-k]);

        // Add currsum value to count of
        // different values of sum.
        um[currsum]++;
    }

    return cnt;
    
}

int main() {
    vector<int> vi {10,2,-2,-20,10};
    int k=-10;

    cout << cntSubarrays(vi,k) << endl;

    return 0;
}