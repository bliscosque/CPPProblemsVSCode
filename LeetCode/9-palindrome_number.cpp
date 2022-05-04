#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        cout << "x: " << x << endl;
        long long int orig=x;
        if (x<0) return false;
        else { 
            long long int rev=0;
            while (x>0) {
                rev=rev*10+x%10;
                x=x/10;
                //cout<<rev<<endl;
            }
            cout << "rev: " << rev << endl;
            return (orig==rev);
        }
    }
};


int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;
    
}