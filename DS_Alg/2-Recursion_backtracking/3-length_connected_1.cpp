#include <bits/stdc++.h>
using namespace std;

//a.k.a. max area of island

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j]=true;
    int cur_sum=1;
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    for (int k=0;k<4;k++) {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if (nx>=0 && nx < m && ny >=0 && ny < n && !visited[nx][ny] && grid[nx][ny]==1) {
            cur_sum+=dfs(grid,visited,nx,ny,m,n);
        }
    }
    return cur_sum;
}

int findMaxBlock(vector<vector<int>> &grid)  {
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<bool>> visited(m,vector<bool>(n,false));

    int largest=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (!visited[i][j] && grid[i][j]==1) {
                int size=dfs(grid,visited,i,j,m,n);
                largest=max(largest,size);
                
                cout << "starting from: " << i << " " << j << ": " << size << endl;
            }
        }
    }
    return largest;
}

int main() {
    vector<vector<int>> grid = {{1,1,0,0,0},
                                {0,1,1,0,0},
                                {0,0,1,0,1},
                                {1,0,0,0,1},
                                {0,1,0,1,1}};

    cout << findMaxBlock(grid) << endl;

    return 0;
}