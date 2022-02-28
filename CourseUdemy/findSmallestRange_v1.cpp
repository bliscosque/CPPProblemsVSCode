#include<bits/stdc++.h>
using namespace std;

//first version
//https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
//https://www.youtube.com/watch?v=Fqal25ZgEDo

#define N 5
 
// array for storing the current index of list i
int ptr[501];

// This function takes an k sorted lists in the form of
// 2D array as an argument. It finds out smallest range
// that includes elements from each of the k lists.
void findSmallestRange(vector<vector<int>> arr, int n)
{
    int i, minval, maxval, minrange, minel, maxel, flag, minind;
 
    int k=arr.size();

    // initializing to 0 index;
    for (i = 0; i <= k; i++)
        ptr[i] = 0;
 
    minrange = INT_MAX;
 
    while (1) {
        // for maintaining the index of list containing the minimum element
        minind = -1;
        minval = INT_MAX;
        maxval = INT_MIN;
        flag = 0;
        cout << endl << "NEW ITERATION WHILE" << endl;
 
        // iterating over all the list
        for (i = 0; i < k; i++) {
            cout << "i: " << i << endl;
            // if every element of list[i] is traversed then break the loop
            if (ptr[i] == n) {
                flag = 1;
                cout << "setting flag" << endl;
                break;
            }
            // find minimum value among all the list elements pointing by the ptr[] array
            if (ptr[i] < n && arr[i][ptr[i]] < minval) {
                minind = i; // update the index of the list
                minval = arr[i][ptr[i]];
                cout << "minind: " << minind << endl;
                cout << "minval: " << minval << endl;
            }
            // find maximum value among all the list elements pointing by the ptr[] array
            if (ptr[i] < n && arr[i][ptr[i]] > maxval) {
                maxval = arr[i][ptr[i]];
                cout << "maxval: " << maxval << endl;
            }
        }
 
        // if any list exhaust we will not get any better answer, so break the while loop
        if (flag)
            break;
 
        ptr[minind]++;
 
        // updating the minrange
        if ((maxval - minval) < minrange) {
            minel = minval;
            maxel = maxval;
            minrange = maxel - minel;
            cout << "minel: " << minel << endl;
            cout << "maxel: " << maxel << endl;
            cout << "minrange: " << minrange << endl;
        }
    }
 
    printf("The smallest range is [%d, %d]\n", minel, maxel);
}

int main() {
    vector<vector<int>> nums = {{ 4, 7, 9, 12, 15 },{ 0, 8, 10, 14, 20 },{ 6, 12, 16, 30, 50 }};
    findSmallestRange(nums, 5);
 
    
    return 0;
}