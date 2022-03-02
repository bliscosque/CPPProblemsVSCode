/*
ID: bliscos1
TASK: wormhole
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
//https://www.youtube.com/watch?v=NUBjfjV2uxE&t=834s
#include<bits/stdc++.h>
using namespace std;

int n, ans;
int x[20], y[20], nex[20], paired[20], part[20];

bool check() {
    for (int s=1;s<=n;s++) {
        //does there exist a cycle starting from start?
        int cur=s;
        for (int it=1;it<=n;it++) cur=part[nex[cur]];
        if (cur) return true;
    }
    return false;
}

void dfs() {
    int f=1;
    while (paired[f] && f<=n) f++;
    if (f==n+1) { //everyone is paired
        if (check()) ans++; //check if cycle exists
    }
    for (int s=f+1;s<=n;s++) {
        if (!paired[s]) {
            paired[f] = paired[s] = true;
            part[f] = s;
            part[s] = f;
            dfs();
            paired[f] = paired[s] = false; 
            part[f] = part[s] = 0;
        }
    }
}

int main() {
    ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");

    fin >> n;
    nex[0]=0;
    for (int i=1;i<=n;i++) {
        fin >> x[i] >> y[i];
        nex[i]=0;
        paired[i] = 0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i!=j && y[i]==y[j] && x[j]>= x[i] && (!nex[i] || x[j]<x[nex[i]]))
                nex[i]=j;
        }
    }
    ans=0;
    dfs();
    fout << ans << endl;

    return 0;
}