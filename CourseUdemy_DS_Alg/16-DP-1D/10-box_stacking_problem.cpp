//given an array of boxes (3 integers: height, width, depth)
//maximize stacks
//has to be smaller (in height, width, depth)

//boxes={{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}}
//output: 10
//3 boxes -> height 10 (2+3+5)
//{2,1,2},{3,2,3},{4,4,5}

//1) sort by last element (height)

#include <bits/stdc++.h>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2) {
    return b1[2]>b2[2];
}

bool canPlace(vector<int> b1, vector<int> b2) {
    if (b1[0]>b2[0] && b1[1]> b2[1] && b1[2] > b2[2]) {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> boxes) {
    int n=boxes.size();

    //1.sorting
    sort(boxes.begin(),boxes.end(),compareBoxes);

    //2.DP
    vector<int> dp(n+1,0);

    for (int i=0;i<n;i++) {
        dp[i]=boxes[i][2]; //heigth of the boxes
    }

    for (int i=1;i<n;i++) {
        //check for all boxes whose index is less than i
        for (int j=0;j<i;j++) {
            if (canPlace(boxes[j],boxes[i]) ) {
                int current_height=boxes[i][2];
                if (dp[j]+current_height>dp[i]) {
                    dp[i]=dp[j]+current_height;
                }
            }
        }
    }
    int max_heigth=0;
    for (int i=0;i<n;i++) {
        max_heigth=max(max_heigth,dp[i]);
    }
    return max_heigth;
}


int main() {
    vector<vector<int>> boxes={{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}};
    int height=boxStacking(boxes);
    cout << height << endl;
    return 0;
}