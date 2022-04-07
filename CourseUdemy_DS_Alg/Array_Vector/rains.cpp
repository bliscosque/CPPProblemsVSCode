//given height of "bars", calculate total water that can be hold
//height = {0,1,0,2,1,0,1,3,2,1,2,1}
//output=6

//sol1 - para cada posicao, verificar a direita e a esquerda a barra mais elevada e calcular min(dir,esq) - O(N^2)
//sol2 - criar 2 matrizes auxiliares (dir e esq) com maior valor até entao (O(n))
//                    {0,1,0,2,1,0,1,3,2,1,2,1}
//         ->     dir={0,1,1,2,2,2,2,3,3,3,3,3}
//         <-     esq={3,3,3,3,3,3,3,3,2,2,2,1}
//min(dir,esq)-altura={0,0,1,0,1,2,1,0,0,1,0,0} S=6

#include <iostream>
#include <vector>
using namespace std;

int trappedWater(vector<int> heights) {
    int water=0;
    int n=heights.size();
    
    if (n<=2) return 0;

    vector<int> right(n,0), left(n,0);
    right[0]=heights[0];
    for (int i=1;i<n;i++) {
        right[i]=max(right[i-1],heights[i]);
    }

    left[n-1]=heights[n-1];
    for (int i=n-2;i>=0;i--) {
        left[i]=max(left[i+1],heights[i]);
    }

    for(int i=0;i<n;i++) {
        water+=min(right[i],left[i])-heights[i];
    }

    return water;
}

int main() {
    vector<int> water={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trappedWater(water) << endl;

    return 0;
}