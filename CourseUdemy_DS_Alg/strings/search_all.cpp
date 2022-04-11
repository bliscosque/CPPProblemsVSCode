#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};

    size_t index = big.find(small);
    while (index!=-1) {
        result.push_back(index);
        index=big.find(small, index+1);
        //cout << index << endl;
    }
    return result;
}

int main() {
    string bigString="I liked the movie, acting in movie was great";
    string smallString="movie";
    vector<int> vi=stringSearch(bigString,smallString);
    for (auto i:vi) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}