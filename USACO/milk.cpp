/*
ID: bliscos1
TASK: milk
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;


int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
    vector<pair<int,int>> vf;
    int amTotal, nf;
    int amt, val;

    fin >> amTotal >> nf;
    for (int i=0;i<nf;i++){
        fin >> val >> amt;
        vf.push_back(make_pair(val, amt));
    }

    sort(vf.begin(), vf.end());


    int price=0; 
    for (auto i: vf) {
        //fout << i.first << " " << i.second << endl;

        int pr1 = i.first;
        int am1 = i.second;
        if (amTotal >= am1){
            price+=(am1*pr1);
            amTotal -= am1;
        } 
        else {
            price+=(amTotal*pr1);
            amTotal=0;
        }
        if (amTotal==0) break;
        //fout << amTotal << " " << price << endl;
    }
    fout << price << endl;

    return 0;
}