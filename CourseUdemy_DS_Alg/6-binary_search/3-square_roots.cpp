// given N, P. Find square of P up to N places (without using libraries)
//N=10,P=3
//Output=3.162

//binary search for integer part and linear search for decimal parts
#include<iostream>
using namespace std;

float square_root(int n, int p) {
    int s=0;
    int e=n;
    float ans=0;

    //binary search (integer part)
    while (s<=e) {
        int mid=(s+e)/2;
        if (mid*mid==n) {
            return mid;
        }
        else if (mid*mid < n) {
            ans=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    cout << "int part: " << ans << endl;

    //linear search (decimal part) - for each place

    float inc=0.1;
    for (int place=1;place<=p;place++) {

        while(ans*ans <= n) {
            ans+=inc;
        }
        //1 step back
        ans-=inc;

        inc/=10.0;
    }

    return ans;
}


int main() {
    int n=10,p=3;
    cout << square_root(n,p) << endl;

    return 0;
}