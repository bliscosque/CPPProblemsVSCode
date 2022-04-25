//input - array of integers
//return length highest montain
//montain -> incresing - peak - decreasing
// {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4}
//      = = = = = = = = =         9 de tamanho

// 1 - identify peaks - > anterior e < posterior
// 2 - para cada peak, ir anterior enquanto elemento seja menor / ir posterior enquanto elemento seja maior
#include <bits/stdc++.h>
using namespace std;

int highest_montain(vector<int> arr) {
    int n=arr.size();
    int ans=0;
    vector<int> peak_pos;

    if (n<3) return 0;

    for (int i=1; i<n-1;i++) {
        //cout << "arr[i]: " << arr[i] << endl;
        //cout << "arr[i-1]: " << arr[i-1] << endl;
        //cout << "arr[i+1]: " << arr[i+1] << endl;

        if (arr[i]> arr[i-1] && arr[i] > arr[i+1]) {
            peak_pos.push_back(i);
            //cout << "new peak pos: " << i << " value: " << arr[i] << endl;
        }
    }
    cout << endl;
    for (int i=0;i<peak_pos.size();i++) {
        int sum=1;

        int j=peak_pos[i];

        //cout << "peak pos: " << j << endl;
        //cout << "peak value: " << arr[j] << endl;

        while (j>0 && arr[j-1]<arr[j]) {
            sum++;
            j--;
        }
        
        //cout << "sum1: " << sum;

        j=peak_pos[i];
        while (j<n && arr[j+1]<arr[j]) {
            sum++;
            j++;
        }
        
        //cout << " sum2: " << sum;
        
        ans=max(ans,sum);

    }
    return ans;

}

int main() {
    vector<int> arr={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << highest_montain(arr) << endl;
    return 0;

}