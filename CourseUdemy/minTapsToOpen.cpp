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
    vector<bool> utilizado;
    for (int i=0;i<ranges.size();i++) {
        //cout << i << " " << ranges[i] << endl;
        if (ranges[i]!=0) {
            //cout << "N0: " << i-ranges[i] << " " << i+ranges[i] << endl;
            ranges_pair.push_back(make_pair((i-ranges[i]), (i+ranges[i])));
            utilizado.push_back(false);
        }
    }
    sort(ranges_pair.begin(), ranges_pair.end(), sortbysecDec);
    cout << endl;
    for (auto a: ranges_pair) {
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;
    int i=0;
    
    while (i<n) {
        bool find=false;
        for (int j=0;j<ranges_pair.size();j++) {
            int inicio=ranges_pair[j].first;
            int fim=ranges_pair[j].second;
            cout << "trying " << inicio << " " << fim << " i " << i << endl;
            if (inicio <= i && fim >= i && !utilizado[j] ) {
                cout << "Selecionado: " << inicio << " " << fim << endl;
                i=fim;
                utilizado[j]=true;
                if (res==-1) res=1;
                else res++;
                find=true;
                break;
            }
        }
        cout << "i: " << i << " res: " << res << endl; 
        if (find==false) {
            res=-1;
            break;
        }
    }
    return res;
}

int main() {
    int n=5;
    vector<int> ranges={3,4,1,1,0,0};
    //cout << minTaps(n,ranges) << endl; //1
    int n1=3;
    vector<int> ranges1={0,0,0};
    //cout << minTaps(n1,ranges1) << endl; //-1
    int n2=7;
    vector<int> ranges2={1,2,1,0,2,1,0,1};
    //cout << minTaps(n2,ranges2) << endl;
    int n3=17;
    vector<int> ranges3={0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1};
    cout << minTaps(n3,ranges3) << endl;
    return 0;
}

/* LeetCode - https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/submissions/

Input
7
[1,2,1,0,2,1,0,1]
Output
-1
Expected
3

*/

/*

Input
17
[0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1]
Output
5
Expected
3

*/