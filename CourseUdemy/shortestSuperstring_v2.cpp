#include <bits/stdc++.h>
using namespace std;

//based on https://www.youtube.com/watch?v=6LpQOyiPxY0 and https://github.com/RevathyGovindarasu/LeetCode_codes/blob/master/FindtheShortestSuperstring
//and https://leetcode.com/problems/find-the-shortest-superstring/discuss/1232359/(C%2B%2B)-943.-Find-the-Shortest-Superstring


string shortestSuperstring(vector<string> words) {
        int n = size(words); 
        
        vector<vector<int>> ovlp (n, vector<int>(n)); 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < min(size(words[i]), size(words[j])); ++k)
                    if (words[i].substr(size(words[i]) - k) == words[j].substr(0, k)) {
                        ovlp[i][j] = k; 
                    }
        
        vector<vector<int>> dp(1<<n, vector<int>(n)); // min length of mask ending at bit 
        vector<vector<int>> parent(1<<n, vector<int>(n, -1)); 
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int bit = 0; bit < n; ++bit) {
                if (mask & 1<<bit) {
                    int pmask = mask ^ (1<<bit); 
                    if (pmask) {
                        for (int i = 0; i < n; ++i) {
                            if (pmask & 1<<i) {
                                int val = dp[pmask][i] + size(words[bit]) - ovlp[i][bit]; 
                                if (dp[mask][bit] == 0 || val < dp[mask][bit]) {
                                    dp[mask][bit] = val; 
                                    parent[mask][bit] = i; 
                                }
                            }
                        }
                    }
                    else dp[mask][bit] = size(words[bit]); 
                }
            }
        }
        
        auto it = min_element(begin(dp.back()), end(dp.back())); 
        int mask = (1<<n) - 1, p = it - begin(dp.back()); 
        string ans; 
        while (mask) {
            int pp = parent[mask][p]; 
            if (pp == -1) ans = words[p] + ans; 
            else ans = words[p].substr(ovlp[pp][p]) + ans; 
            mask ^= 1 << p; 
            p = pp; 
        }
        return ans; 
    }

int main() {
    vector<string> words = {"catg", "ctaag", "gcta", "ttca", "atgcatc"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}