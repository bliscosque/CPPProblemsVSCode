/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n<=1) return 0;
        vector<bool> isPrime(n,true);
        isPrime[0]=isPrime[1]=false;
        for (long long int i=2;i*i<n;i++) {
            if (isPrime[i]) {
                for (long long int j=i*i;j<n;j+=i) 
                    isPrime[j]=false;
            }
        }
        int sum=0;
        for (int i=2;i<n;i++) {
            if (isPrime[i]) sum++;
        }
        return sum;
    }
};
// @lc code=end

