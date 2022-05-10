//you are given an array and you need to count number of triplets with indices (i,j,k) 
//such that the elem at those indices are in geometric progression for a given common ratio r
// and i (i<j<k) -> posicao de i < posicao de j < posicao de k

//input={1,16,4,16,64,16}
//r=4

//3

//1,4,16
//1,4,16
//4,16,64

//mantain 2 maps -> 1 com frequencia a esquerda e outro com frequencia a direita do elemento
//esquerda -> elem/ratio
//direita -> elem*ratio

//inicia com todos elementos no da direita

#include <bits/stdc++.h>
using namespace std;
int count_triplets(vector<int> vi, int r) {
    int n=vi.size();
    unordered_map<long,long> right,left;

    //init right map with freq, left will be with freq 0
    for (auto x: vi) {
        right[x]++;
        left[x]=0;
    }

    //iterate left to right
    int ans=0;
    for (int i=0;i<n;i++) {
        right[vi[i]]--;
        if (vi[i]%r==0) {
            long a=vi[i]/r;
            long b=vi[i];
            long c=vi[i]*r;

            ans+=left[a]*right[c];
        }
        left[vi[i]]++;
    }
    return ans;
}

int main() {
    vector<int> vi={1,16,4,16,64,16};
    int r=4;
    cout << count_triplets(vi,r);

    return 0;
}
