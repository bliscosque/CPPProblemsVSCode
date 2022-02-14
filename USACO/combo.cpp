/*
ID: bliscos1
TASK: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

int conv_circ(int i, int n) {
    if (i>0 && i<=n) return i;
    if (i<=0) {
        while (i<=0) {
            i=i+n;
        }
        return i;
    }
    if (i>n) {
        if (i%n!=0) return (i%n);
        else return 1;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");
    int n;
    int c1,c2,c3;
    int m1,m2,m3;
    set<string> vs;
    vector<int> key, mkey;
    fin >> n;
    fin >> c1 >> c2 >> c3;
    fin >> m1 >> m2 >> m3;
    key.push_back(c1);key.push_back(c2);key.push_back(c3);
    mkey.push_back(m1);mkey.push_back(m2);mkey.push_back(m3);

    for (int i=-2;i<=2;i++) {
        for (int j=-2;j<=2;j++) {
            for (int k=-2;k<=2;k++) {
                int v1=conv_circ(key[0]+i,n);
                int v2=conv_circ(key[1]+j,n);
                int v3=conv_circ(key[2]+k,n);
                string s=(to_string(v1)+","+to_string(v2)+","+to_string(v3));
                vs.insert(s);

                int vm1=conv_circ(mkey[0]+i,n);
                int vm2=conv_circ(mkey[1]+j,n);
                int vm3=conv_circ(mkey[2]+k,n);

                //if (i==1) {
                //    cout << key[0]+i << " " << key[1]+j << " " << key[2]+k  << endl;
                //    cout << v1 << " " << v2 << " " << v3 << endl;
                //}
                string sm=(to_string(vm1)+","+to_string(vm2)+","+to_string(vm3));
                vs.insert(sm);
            }
        }
    }
    fout << vs.size() << endl;
    //for (auto v:vs) {
    //    fout << v << endl;
    //}

    return 0;
}



/*
  > Run 2: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.007 seconds;
        it used 1352 KB of memory. Your answer length was 3; the correct
        length is 2. At character number 1, your answer says '2' while the
        correct answer says '1'. 

        Here are the respective outputs:
        ----- our output ---------
        1
        ---- your output ---------
        27
        --------------------------

        ------ Data for Run 2 [length=14 bytes] ------
        1 
        1 1 1 
        1 1 1 
        ----------------------------
*/

/*
 > Run 10: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.007 seconds;
        it used 1408 KB of memory. At character number 3, your answer says
        '8' while the correct answer says '9'. 

        Here are the respective outputs:
        ----- our output ---------
        249
        ---- your output ---------
        248
        --------------------------

        ------ Data for Run 10 [length=18 bytes] ------
        100 
        100 1 2 
        4 5 6 
        ----------------------------
*/