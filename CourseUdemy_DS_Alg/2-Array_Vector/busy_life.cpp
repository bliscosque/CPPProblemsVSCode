#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>  activitie1, pair<int,int> activitie2) {
    return activitie1.second < activitie2.second;
}

int countActivites(vector<pair<int,int> > activities){
    int ans=1;
    sort(activities.begin(),activities.end(),comp);

    // for (auto el:activities) {
    //     cout << el.first << "," << el.second << endl;
    // }

    int last=activities[0].second;
    for (int i=0;i<activities.size();i++){
        if (last <= activities[i].first) {
            last=activities[i].second;
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<pair<int,int>> vpii = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    cout << countActivites(vpii) << endl;

    return 0;
}   