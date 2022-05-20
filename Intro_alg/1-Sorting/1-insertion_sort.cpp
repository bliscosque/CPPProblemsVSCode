//inicia com uma mao vazia e outra mao com os elementos
//para cada elemento, compara os da mao "vazia" enquanto for maior, deslocando os mesmos para ter um espaco vazio
//posiciona esse elemento ali

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &vi) {
    int n=vi.size();
    for (int i=1;i<n;i++) {
        int key=vi[i];
        //insert the "key" into the sorted subarray vi[0:i-1]
        int j=i-1;
        while (j>=0 && vi[j]>key) {
            vi[j+1]=vi[j];
            j--;
        }
        vi[j+1]=key;
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