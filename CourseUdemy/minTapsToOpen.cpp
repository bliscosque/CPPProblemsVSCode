#include<bits/stdc++.h>
using namespace std;

bool sortbysecDec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}

int minTaps(int n, vector<int> ranges) {
    int res=-1;
    vector<pair<int, int>> ranges_pair;
    for (int i=0;i<ranges.size();i++) {
        //cout << i << " " << ranges[i] << endl;
        if (ranges[i]!=0) {
            //cout << "N0: " << i-ranges[i] << " " << i+ranges[i] << endl;
            ranges_pair.push_back(make_pair((i-ranges[i]), (i+ranges[i])));
        }
    }
    // cout << endl;
    // for (auto a: ranges_pair) {
    //     cout << a.first << " " << a.second << endl;
    // }
    sort(ranges_pair.begin(), ranges_pair.end(), sortbysecDec);
    // cout << endl;
    // for (auto a: ranges_pair) {
    //     cout << a.first << " " << a.second << endl;
    // }
    int i=0;
    int ultimo_usado=0;
    while (i<n) {
        for (int j=ultimo_usado;j<ranges_pair.size();j++) {
            int inicio=ranges_pair[j].first;
            int fim=ranges_pair[j].second;
            if (inicio >= i && fim <= i ) {
                i=fim;
                ultimo_usado=j;
                if (res==-1) res=1;
                else res++;
            }
        }
        cout << "i: " << i << " res: " << res << "ultimo usado: " << ultimo_usado << endl; 
    }
    return res;
}

int main() {
    int n=5;
    vector<int> ranges={3,4,1,1,0,0};
    cout << minTaps(n,ranges) << endl; //1
    int n1=3;
    vector<int> ranges1={0,0,0};
    //cout << minTaps(n1,ranges1) << endl; //-1
    
    return 0;
}