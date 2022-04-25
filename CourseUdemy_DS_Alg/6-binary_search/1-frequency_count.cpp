//given sorted array, how many times a element k is ocurring

//input={0,1,1,1,1,2,2,2,3,4,4,5,10}
//key=2
//output = 3

//opc 1 - linear O(n)
//opc 2 - binary search for 1st and last ocurrency (lower_bound and upper_bound)
   //idea: continue doing binary search and "updating" answer in case there is smaller elements

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound(vector<int> arr, int key) {
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while (s<=e) {
        int mid=(s+e)/2;

        if (arr[mid]==key) {
            ans=mid;
            e=mid-1;
        }
        else if (arr[mid] > key) {
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return ans;
}

int upper_bound(vector<int> arr, int key) {
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while (s<=e) {
        int mid=(s+e)/2;

        if (arr[mid]==key) {
            ans=mid;
            s=mid+1;
        }
        else if (arr[mid] > key) {
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr={0,1,1,1,1,2,2,2,3,4,4,5,10};
    cout << lower_bound(arr,2) << endl;
    cout << upper_bound(arr,2) << endl;
    cout << upper_bound(arr,2)-lower_bound(arr,2) +1 << endl;

    //STL --- upper_bound return alg from elem+1
    cout << upper_bound(arr.begin(), arr.end(),2) - lower_bound(arr.begin(),arr.end(), 2) << endl;

    return 0;
}