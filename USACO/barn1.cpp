/*
ID: bliscos1
TASK: barn1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;

bool sortPairDec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first > b.first);
}


int main() {
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
    int max, nstall, ncow;
    vector<int> cowP;
    vector<pair<int,int>> dif;
    //vector<int> vstall(nstall,0)

    fin >> max >> nstall >> ncow;
    if (max>=ncow) {
        fout << ncow << endl;
        return 0;
    } 

    for (int i=0;i<ncow;i++) {
        int j;
        fin >> j;
        cowP.push_back(j);
        //vstall[j]=1;
    }
    sort (cowP.begin(), cowP.end());
    for (int i=0;i<ncow-1;i++) {
        int d=cowP[i+1]-cowP[i];
        dif.push_back(make_pair(d, i));
    }
    sort (dif.begin(), dif.end(), sortPairDec);

    for (auto x: dif) {
        //cout << x.first << " " << x.second << endl;
    }

    vector<int> difUtil;
    for (int i=0;i<max-1;i++) {
        difUtil.push_back(dif[i].second);
        //cout << "Pos util: " << dif[i].second << endl;
    }
    difUtil.push_back(0);
    difUtil.push_back(ncow-1);
    sort(difUtil.begin(), difUtil.end());

    int soma=0;
    int posI, posF;
    for (int i=0;i<max;i++) {
        int posI=0;
        if (i>0)
            posI=difUtil[i]+1;

        int posF=difUtil[i+1];

        //cout << "PosI: " <<posI << endl;
        //cout << "Posf: " << posF << endl;

        int valI=cowP[posI];
        int valF=cowP[posF];
        


        //cout << "ValI: " << valI << endl;
        //cout << "ValF: "<< valF << endl;
        
        soma += valF-valI+1;
        //cout << "Soma: " << soma << endl;
    }

    fout << soma << endl;

    return 0;
}

/*
0 3
1 4
2 6
3 8
SOMA: 6

4 14
5 15
6 16
7 17
8 21
SOMA: 8+6=14

9 25
10 26
11 27
12 30
13 31
SOMA: 7+14=21

14 40
15 41
16 42
17 43
SOMA: 4+21=25
*/


/*
  > Run 5: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.004 seconds;
        it used 1424 KB of memory. Your answer length was 5; the correct
        length is 3. At character number 1, your answer says '-' while the
        correct answer says '1'. 

        Here are the respective outputs:
        ----- our output ---------
        10
        ---- your output ---------
        -426
        --------------------------

        ------ Data for Run 5 [length=41 bytes] ------
        50 200 10 
        18 
        69 
        195 
        38 
        73 
        28 
        6 
        172 
        53 
        99 
        ----------------------------
*/