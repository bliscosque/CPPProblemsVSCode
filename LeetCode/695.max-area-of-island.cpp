/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> & visited, int m, int n, int i, int j) {
        visited[i][j]=1;
        int cnt=1;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};

        for (int k=0;k<4;k++) {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if (ni>=0 && ni <m && nj>=0 && nj < n && !visited[ni][nj] && grid[ni][nj]==1) {
                cnt+=dfs(grid,visited,m,n,ni,nj);
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        int largest=0;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i][j] && grid[i][j]==1) {
                    int cnt=dfs(grid,visited,m,n,i,j);
                    largest=max(largest,cnt);
                }
            }
        }

        return largest;

    }
};
// @lc code=end

