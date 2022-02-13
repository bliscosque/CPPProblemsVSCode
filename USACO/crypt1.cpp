/*
ID: bliscos1
TASK: crypt1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;

vector<int> vnum;
set<int> snum;

bool checkP1(int i) { //must be format ***
    if (i>1000) return false;
    else {
        int a=i%10;
        if (snum.find(a)==snum.end()) return false;
        a=(i/10)%10;
        if (snum.find(a)==snum.end()) return false;
        a=(i/100);
        if (snum.find(a)==snum.end()) return false;
    }
    return true;
}

bool checkPF(int i) { //must be format ****
    if (i>10000) return false;
    else {
        int a=i%10;
        if (snum.find(a)==snum.end()) return false;
        a=(i/10)%10;
        if (snum.find(a)==snum.end()) return false;
        a=(i/100)%10;
        if (snum.find(a)==snum.end()) return false;
        a=(i/1000);
        if (snum.find(a)==snum.end()) return false;
    }
    return true;
}

int main() {
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
    int n, nsol=0;
    
    vector<int> numA;
    vector<int> numB;
    fin >> n;
    for (int i=0;i<n;i++) {
        int a;
        fin >> a;
        vnum.push_back(a);
        snum.insert(a);
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                int num=vnum[i]*100+vnum[j]*10+vnum[k];
                if (num>=100) //no leading 0
                    numA.push_back(num);
            }
        }
    }

    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
                int num=vnum[i]*10+vnum[j];
                if (num >=10) //no leading 0
                    numB.push_back(num);
        }
    }

    int resA, resB, resF;
    
    for (int i=0;i<numA.size();i++) {
        for (int j=0;j<numB.size();j++) {
            //elaborate first multip
            resA=numA[i]*(numB[j]%10);
            if (checkP1(resA)) {
                resB=numA[i]*(numB[j]/10);
                if (checkP1(resB)) {
                    resF=numA[i]*numB[j];
                    if (checkPF(resF)) {
                        nsol++;
                        //cout << numA[i] << " " << numB[j] << " " << resA << " " << resB << " " << resF << endl;
                    }
                }
            }
        }
    }

    fout << nsol << endl;

    return 0;
}