//divide & conquer alg (divide, conquer, combine)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &vi, int p, int q, int r) {
    int nL=q-p+1; //size of left part
    int nR=r-q; //size of right part (q+1...r)
    vector<int> L(nL), R(nR);
    for (int i=0;i<nL;i++) { //copy left part to new vector
        L[i]=vi[p+i];
    }
    // for (auto i: L) {
    //     cout << i << "-";
    // }
    // cout << endl;

    for (int j=0;j<nR;j++) { //copy right part to new vector
        R[j]=vi[q+j+1];
    }
    
    // for (auto i: R) {
    //     cout << i << "-";
    // }
    // cout << endl;

    int i=0, j=0, k=p;
    //as long as each of the arrays L and R contains unmerged element, copy the smallest unmerged elem back
    while(i<nL && j<nR) {
        if (L[i] <= R[j]) {
            vi[k]=L[i];
            i++;
        }
        else {
            vi[k]=R[j];
            j++;
        }
        k++;
    }
    //copy remaining elemen
    while (i<nL) {
        vi[k]=L[i];
        i++;
        k++;
    }
    while (j<nR) {
        vi[k]=R[j];
        j++;
    }
}

void merge_sort(vector<int> &vi, int p, int r) {
    if (p>=r) return;//zero or one elem
    int q=(p+r)/2;
    merge_sort(vi,p,q);
    merge_sort(vi,q+1,r);
    merge(vi,p,q,r);
}

int main() {
    vector<int> vi={0,10,2,4,1,2};
    //vector<int> vi2={0,2,10,1,1,2};
    merge_sort(vi,0,5);
    //merge (vi2,0,2,5);
    for (auto i:vi) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
} 