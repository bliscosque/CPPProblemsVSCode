//merge k sorted arrays to produce a single sorted array with same elements
//used in external sorting alg -> handle massive amt of data

//K=3
// A1={1,3,15}
// A2={2,4,6}
// A3={0,9,10,11}

// 0 1 2 3 4 6 9 10 11 15

//manter 3 ponteiros... para saber o minimo, criar um min heap

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arrays) {
    int k=arrays.size();
    //heap node contains element, index, index_of_matrix
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    vector<int> output;

    //init the heap
    for (int i=0;i<k;i++) {
        int elem=arrays[i][0];
        q.push({elem,i,0});
    }

    //start popping elem
    while (!q.empty()) {
        //cout << q.size() << endl;
        auto top=q.top();
        q.pop();

        int elem=top[0];
        int ar_idx=top[1];
        int el_idx=top[2];

        output.push_back(elem);
        if (el_idx+1 < arrays[ar_idx].size()) {
            int next_element = arrays[ar_idx][el_idx+1];
            q.push({next_element,ar_idx,el_idx+1});        }
    }
    return output;
}

int main() {
    vector<vector<int>> arr={{1,3,15},{2,4,6},{0,9,10,11}};

    vector<int> result = mergeKArrays(arr);

    for (auto x:result) {
        cout << x << " ";
    }

    return 0;
}