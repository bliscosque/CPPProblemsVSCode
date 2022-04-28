//given set non-negative int, and a value sum
//determine if there is a senset with given sum

//arr={10,12,15,6,19,20}
//sum=16
//output=Yes
//if yes, how many subsets are there

#include <vector>
#include <iostream>
using namespace std;

int countSubsetSum(vector<int> arr, int sum, int i) {
    int n=arr.size();
    if (i==n) {
        if (sum==0) return 1;
        else return 0;
    }

    int inc=countSubsetSum(arr,sum-arr[i],i+1);
    int exc=countSubsetSum(arr,sum,i+1);
    return inc+exc;
}

int main() {
    vector<int> arr={1,2,3,4,5};
    int sum=6;

    cout << countSubsetSum(arr,sum,0) << endl;

    return 0;
}