//Divide & Conquer alg, with 3 steps
//1) split the current ordering items
//2) sort the subset
//3) merge both subsets

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int s, int e) {
    //1 part from start to mid, another from mid+1 to end
    int i=s;
    int m=(s+e)/2;
    int j=m+1;

    vector<int> temp;
    while (i<=m && j<=e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        }else {
            temp.push_back(array[j]);
            j++;
        }
    }
    //this previoous loop will break when one of the subarrays exhausted

    //copy remaining elements from first or second array
    while (i<=m) {
        temp.push_back(array[i++]);
    }
    while (j<=e) {
        temp.push_back(array[j++]);
    }

    //copy back elements from temp to original array
    int k=0;
    for (int idx=s;idx<=e;idx++) {
        array[idx]=temp[k++];
    }
    return;
}

void mergesort(vector<int> &array, int s, int e) {
    //base case
    if (s>=e) { //max of 1 elem
        return;
    }

    //rec case
    int mid=(s+e)/2;
    mergesort(array,s,mid);
    mergesort(array, mid+1,e);
    return merge(array, s, e);
}

int main() {

    vector<int> arr{10,5,2,0,7,6,4};
    int s=0; //start
    int e=arr.size()-1; //end
    mergesort(arr,s,e);
    for(int x:arr) {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}