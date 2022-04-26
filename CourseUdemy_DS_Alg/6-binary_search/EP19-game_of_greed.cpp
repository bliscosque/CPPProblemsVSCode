//playing a game with K friends
//array of N coins
//goal: maximize the minimun partition

//k=3
//coins={1,2,3,4}
//3 (1+2),(3),(4)

//search space: | min: smallest coin | max:sum of all elements

#include<bits/stdc++.h>
using namespace std;

bool divideAmongK(vector<int> arr,int k,int minCoins) {
    int partitions=0;
    int curr_friend=0;
    int n=arr.size();

    for (int i=0;i<n;i++) {
        if (curr_friend + arr[i] >=minCoins) {
            partitions++;
            curr_friend=0;
        }
        else {
            curr_friend+=arr[i];
        }
    }
    return partitions>=k;
}

int getCoins(vector<int> arr, int k){
    //sort(arr.begin(),arr.end());

    int s=arr[0];
    int e=0;
    int ans=-1;
    for(auto el: arr) e+=el;

    while (s<=e) {
        int mid=(s+e)/2;
        bool isPossible=divideAmongK(arr,k,mid);
        if (isPossible) {
            s=mid+1;
            ans=mid;
        }
        else {
            e=mid-1;
        }
    }   
    return ans;
}

int main() {
    int k=3;
    vector<int> coins={1,2,3,4}; 
    cout << getCoins(coins,k) << endl;
    return 0;
}