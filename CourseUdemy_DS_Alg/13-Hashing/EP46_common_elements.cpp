//return sorted list of common elements in both vectors
#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    unordered_map<int,int> um;
    vector<int> ans;
    for (int i:v1) {
        um[i]++;
    }
    for (int i:v2) {
        um[i]++;
    }
    for (auto a:um) {
        if (a.second>1) {
            ans.push_back(a.first);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> v1={1,45,54,71,76,12};
    vector<int> v2={1,7,5,4,6,12};
    vector<int> ans=commonElements(v1,v2);
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}