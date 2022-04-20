#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> pa, pair<string,int> pb) {
    return pa.second < pb.second;
}

int badness(vector<pair<string,int> > teams){
    sort(teams.begin(),teams.end(), comp);
    int i=1;
    int badness=0;    
    for (auto a:teams) {
        badness+=abs(a.second-i);
        i++;
    }
    return badness;
}

int main() {
    vector<pair<string,int>> vp = {{"WinOrBooze", 1}, {"BallOfDuty", 2}, {"WhoKnows", 2}, {"BholeChature", 1},{"DCECoders",5}, 
                                    {"StrangeCase", 7}, {"WhoKnows", 7}};

    cout << badness(vp) << endl;
    return 0;
}