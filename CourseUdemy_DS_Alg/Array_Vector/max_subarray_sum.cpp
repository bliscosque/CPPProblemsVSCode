#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr) {
    int n = arr.size();
    int cur_sum=0, max_sum=0;

    for(int elem: arr) {
        cur_sum+=elem;
        max_sum=max(max_sum,cur_sum);
        if (cur_sum<0) cur_sum=0;
    }

    return max_sum;
}

int main() {
    vector<int> arr={-1,2,3,4,-2,6,-8,3};
    cout << maxSubarraySum(arr) << endl;

    return 0;
}