//given array and target sum (S)
//calculate all triplets that have sum S
//show results in ascending orders

//steps
//1 - sort (NlogN)
//2 - select a[i] and solve pair sum from a[j]...a[k] - O(n^2)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum) {
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    int n=arr.size();
    
    for (int i=0;i<n-2;i++) { //se tiver menos de 2 elementos, nao tem como testar
        //two pointers
        int j=i+1;
        int k=n-1;

        while (j<k) {
            int current_sum=arr[i];
            current_sum+=arr[j];
            current_sum+=arr[k];

            if (current_sum==sum) {
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if (current_sum > sum) k--;
            else j++;
        }

    }
    return ans;

}

int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9,15};
    int S=18;

    auto result=triplets(arr,S);
    for (auto sol: result) {
        for (auto v:sol) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}