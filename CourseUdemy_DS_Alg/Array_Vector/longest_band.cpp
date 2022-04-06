//given array with N integer, length of longest band
//band -> subsequence of consecutive integers
//arr = {1,9,3,0,18,5,2,4,10,7,12,6}
//output = 8 {0,1,2,3,4,5,6,7}

//sol1 - ordenar e buscar os bands (observar o maior) -> O(nlogn)
//sol2 - percorrer a lista e verificar se é um valor "de inicio" para um band 
//       adicionar elementos num unordered_set e buscar pelos bands a partir dos inicios O(n)

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int longestBand(vector<int> arr) {
    int ans=0;
    int n=arr.size();
    unordered_set<int> us;

    for (int i=0;i<n;i++) {
        us.insert(arr[i]);
    }

    for (int i=0;i<n;i++) {
        int prev=arr[i]-1;
        if (us.find(prev)==us.end()) { //nao existe elemento anterior... verificar um chain a partir desse elemento
            int sum=1;
            int j=arr[i]+1;
            while (us.find(j)!=us.end()) {
                j++;
                sum++;
            }
            ans=max(ans,sum);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout << longestBand(arr) << endl;
    return 0;
}