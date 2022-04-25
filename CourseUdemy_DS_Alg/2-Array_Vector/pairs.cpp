//given an array containing N integers, S=sum target
//find 2 distinct integer that can pair up to form S

//1- Brute force (O(n^2))
//2- sort -- para cada numero, buscar se o complemento da soma esta presente
//3- unordered_sort --- O(n) --- para cada numero, buscar o complemento

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int S) {
    unordered_set<int> s;
    vector<int> ans;
    for (int i=0;i<arr.size();i++) {
        int x=S-arr[i];
        if (s.find(x) != s.end()) {
            ans.push_back(x);
            ans.push_back(arr[i]);
            return ans;
        }
        s.insert(arr[i]);
    }
    return {};
}


int main() {
    vector<int> arr={10,5,2,3,-6,9,11};
    int S=4;
    auto p=pairSum(arr,S);
    if (p.size() == 0) {
        cout << "Resp nao encontrada";
    }
    else {
        cout << p[0] <<"," << p[1]<<endl; 
    }

    return 0;
}