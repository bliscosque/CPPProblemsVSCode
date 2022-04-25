//input sorted integers array
//rotated about a pivot point 
//finds index of given elem

//input={7,9,10,1,2,3,4,5,6}
//elem=4
//output=6

//{4,5,6,7,0,1,2,3}
//k=6
#include <bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> a, int key) {
    int n=a.size();

    int s=0;
    int e=n-1;

    while (s<=e) {
        int mid=(s+e)/2;
        if (a[mid]==key) {
            return mid;
        }
        //2 cases
        if (a[s] <= a[mid]) {             //left of pivot
            if (key>=a[s] && key <=a[mid]) {
                e=mid-1;
            }
            else {
                s=mid+1;
            }

        }
        else {            //right of the pivot
            if (key>=a[mid] && key <=a[e]) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
    }

    return -1;

}

int main() {
    vector<int> input={4,5,6,7,0,1,2,3};
    int k=10;

    cout << rotated_search(input,k) << endl;

    return 0;
}