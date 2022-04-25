#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


pair<int,int> subarraySorting(vector<int> a){
    //Opc 1 - sort + ver diferenca (NlogN)
    //Opc 2
    //find min out of order elem


    //imrplementing opc 1

    vector<int> b=a;
    sort(b.begin(),b.end());
    int n=a.size();
    int s=0, e=n-1;
    for (;s<n;s++) {
        //cout << s << " " << a[s] << " " << b[s] << endl;
        if (a[s]!=b[s]) break;
    }

    for (;e>=0;e--) {
        if (a[e]!=b[e]) break;
    }
    if (s<e) {
        return {s,e};
    }
    return {-1,-1};

    /* NOT WORKING FOR SOME TCs
    for (auto i: a) {
        cout << i << " ";
    }
    cout << endl;
    
    int n=a.size();
    int OoO=-1;
    
    for (int i=0;i<n-2;i++) {
        if (a[i] > a[i+1]) {
            if (OoO==-1) OoO=i+1;
            else {
                if (a[OoO] > a[i]) OoO=i+1;
            }
        }
    }
    
    if (OoO==-1) return {-1,-1};

    //where this element should be put
    int i;
    for (i=0;i<n-2;i++) {
        if (a[i] >= a[OoO]) break;
    }
  
    return {i,OoO};

    */
}

int main() {
    //vector<int> arr={0,2,4,7,10,11,7,12,13,14,16,19,29}; //4 6
    vector<int> arr={0,1,2,3,4,5,8,6,7,9,10,11};
    pair<int,int> pii = subarraySorting(arr);
    cout << pii.first << " " << pii.second << endl;
    return 0;
}