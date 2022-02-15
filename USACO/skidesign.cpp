/*
ID: bliscos1
TASK: skidesign
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;


int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
    int nhills, h;
    vector<int> hills;
    fin >> nhills;
    for (int i=0;i<nhills;i++) {
        fin >> h;
        hills.push_back(h);
    }

    sort(hills.begin(), hills.end());
    int hmin=hills[0];
    int hmax=hills[nhills-1];
    cout << hmin << " " << hmax << endl;

    int conv_amt=hmax-hmin-17;
    cout << conv_amt << endl;
    int v1=conv_amt/2;
    int v2=conv_amt-v1;
    cout << v1 << " " << v2 << endl;
    int pTot=v1*v1+v2*v2;
    fout << pTot << endl; 
    

    return 0;
}

/*Run 2: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.004 seconds;
        it used 1352 KB of memory. Your answer length was 5; the correct
        length is 6. At character number 1, your answer says '3' while the
        correct answer says '2'. 

        Here are the respective outputs:
        ----- our output ---------
        22946
        ---- your output ---------
        3445
        --------------------------

        ------ Data for Run 2 [length=150 bytes] ------
        50 
        50 
        84 
        22 
        44 
        38 
        0 
        46 
        66 
        22 
        73 
        25 
        92 
        5 
        56 
        13 
        73 
        48 
        32 
        42 
        91 
        3 
        100 
        97 
        8 
        27 
        34 
        73 
        58 
        42 
        80 

        ... [and more] ...
        ----------------------------

          Your program printed data to stdout.  Here is the data:
          -------------------
          83
          41_42
          -------------------

*/