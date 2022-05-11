//given N cartesian points in a 2D plane, find the number of right base triangles such that the 
// base or the perpendicular is parallel to the X or Y-axis


//N=3
//{{0,0},{2,0},{0,1}}

//1

//N=5
//{{1,2},{2,0},{2,2},{2.3},{4,2}}

//4

//for one point (x,y), the other point will have same y, the other will have the same x
//for each point, cnt points with same x and points with same y

#include <bits/stdc++.h>
using namespace std;
int count_triangles(vector<pair<int,int>> &points) {
    unordered_map<int,int> um_x; //key, freq
    unordered_map<int,int> um_y; //key, freq 

    for (auto p:points) {
        int x=p.first;
        int y=p.second;

        um_x[x]++;
        um_y[y]++;
    }
    int count=0;
    for (auto p:points) {
        int x=p.first;
        int y=p.second;

        int fx=um_x[x];
        int fy=um_y[y];

        // if (fx>=1 && fy >=1) {
            count+= (fx-1)*(fy-1);
        // }
    }
    return count;
}

int main() {
    vector<pair<int,int>> points;
    points.push_back({1,2});
    points.push_back({2,0});
    points.push_back({2,2});
    points.push_back({2,3});
    points.push_back({4,2});

    
    cout << count_triangles(points);
    return 0;
}