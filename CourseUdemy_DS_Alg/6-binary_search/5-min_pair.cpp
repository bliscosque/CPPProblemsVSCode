//given 2 non-empty array
//find pair whose abs difference is minimun

//a1={-1,5,10,20,3}
//a2={26,134,135,15,17}

//sample output = [20,17]

//step1 - sort a2
//a2={15,17,26,134,135}
//using lower_bound, for closest element from each element (usar LB e tambem LB-1)

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2) {
    //sort one of the arrays
    sort(a2.begin(),a2.end());

    int p1, p2;
    int diff=INT_MAX;
    //iterate over the other array and look for closest element in the second array
    for (int x: a1) {
        auto lb=lower_bound(a2.begin(),a2.end(),x)-a2.begin(); //to return the index instead of the pointer
        //left element 
        if (lb>=1 && x - a2[lb-1] < diff) {
            diff=x-a2[lb-1];
            p1=x;
            p2=a2[lb-1];

        }
        //right elem
        if (lb!=a2.size() && a2[lb]-x < diff) {
            diff=a2[lb]-x;
            p1=x;
            p2=a2[lb];
        }
    }
    cout << "Min Pair: " << p1 << " " << p2 << endl;
}

int main() {
    vector<int> a1={-1,5,10,20,3};
    vector<int> a2={26,134,135,15,17};
    min_pair(a1,a2);

    return 0;
}