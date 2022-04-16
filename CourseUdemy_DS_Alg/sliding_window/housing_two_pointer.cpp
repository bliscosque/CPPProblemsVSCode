//area de um lado da rua de tamanhos A[1],A[2],...A[N]
//quer construir casa com K de area (continuo)

//EX:
// plots={1,3,2,1,4,1,3,2,1,1,2}
// k=8
//answer in indices
// 2 5 (2+1+4+1)
// 4 6 (4+1+3)
// 5 9 (1+3+2+1+1)

//1) brute force -> N^3 ->N^2 - para iterar nos elementos *N para somar os elementos
//2) using prefix sum -> N^2 -> a soma eh feita em O(1)
// mat={1,3,2,5}
// ps ={1,4,6,11} //soma ate elemento X 
// soma de elemento i ate elemento j = ps(j)-ps(i-1)
//3) para cada elemento i de ps, calcular um j, onde (ps(j)-ps(i))==k
// buscar j usando binary search (logN)
//NlogN

//4) sliding window (O(n))
//manter 2 ponteiros, i e j, inicialmente apontando ao primeiro elemento
//expandir a janela, ate soma <= k
//se soma passar, reduzir janela e subtrair ate soma <=k
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void housing(vector<int> arr, int k) {
    int n=arr.size();
    int i=0,j=0;
    int curSum=0;
    while (i<n) {
        cout << "testing i: " << i << " j: " << j << " current sum: " << curSum << endl;
        if (curSum+arr[i] <=k ) {
            curSum+=arr[i];
            if (curSum==k) {
                cout << "sol: " << j << " " << i << endl;
            }
            i++;

        }
        else {
            curSum-=arr[j];
            j++;
        }
    }
}

int main() {
    vector<int> plots={1,3,2,1,4,1,3,2,1,1,2};
    int k=8;
    housing(plots,k);

    return 0;
}