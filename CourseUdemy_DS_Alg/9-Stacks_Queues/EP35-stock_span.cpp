//https://www.youtube.com/watch?v=29Jn5xPGJHg
#include<bits/stdc++.h>
using namespace std;

//para cada i, span é [i-maior anterior]
//mantain stack with: day (idx) and value
//  if val of today < val yesterday... just add and calculate span
//  else remove elements > val from the stack
// corner case: if stack is empty, idx+1 (all days)

vector<int> stockSpan(vector<int> v) {
    vector<int> ans;
    int n=v.size();

    stack<int> s;
    vector<int> res;
    res.push_back(1); //first is always 1
    s.push(0);

    for (int i=1;i<n;i++) {
        int currentPrice=v[i];
        //topmost element that is igher than current price
        while (!s.empty() && v[s.top()] <= currentPrice) {
            s.pop();
        }
        if (!s.empty()) {
            int prev_highest=s.top();
            res.push_back(i-prev_highest);
        }
        else {
            res.push_back(i+1);
        }
        s.push(i);
    }
    return res;
}

int main() {

    vector<int> vi={100,80,60,70,60,75,85}; // 1 1 1 2 1 4 6
    
    vector<int> ans=stockSpan(vi);
    
    for (auto i:ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}