//busca cada um dos menores elementos no restante da matriz e insere este elemento na posicao atual

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &vi) {
    int n=vi.size();
    for (int j=0;j<n-1;j++) {
        int smallest=j;
        for (int i=j+1;i<n;i++) {
            if (vi[i] < vi[smallest]) {
                smallest=i;
            }
        }
        swap(vi[j],vi[smallest]);
    }
}

int main() {
    vector<int> vi={0,10,2,4,1,2};
    insertion_sort(vi);
    for (auto i:vi) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
} 