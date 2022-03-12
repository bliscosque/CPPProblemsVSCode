/*
ID: bliscos1
TASK: skidesign
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//help from:
//https://www.youtube.com/watch?v=NwOXXtCk4Xo

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
    int pTotMin=INT_MAX; 
    int vmin; 
    int vmax=17;
    
    for (int i=0;i<100-17;i++) {
        vmin=i;
        vmax=vmin+17;
        int pTot=0;
        for (int j=0;j<nhills;j++) {
            //cout << "testing: "<< vmin << " " << vmax <<endl;
            if (hills[j] < vmin) {
                pTot+=pow((vmin-hills[j]),2);
            }
            if (hills[j] > vmax) {
                pTot+=pow((hills[j]-vmax),2);
            }

        }
        //cout << "tot" << pTot << endl;
        pTotMin=min(pTotMin,pTot);
    }

    fout << pTotMin << endl; 
    

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