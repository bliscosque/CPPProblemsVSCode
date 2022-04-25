//smallest subarray that needs to be sorted
//return indexes
//Input={1,2,3,4,5,8,6,7,9,10,11}
//Output=[5,7]

//sol1 = sort array, verificar até elementos que sao iguais, da direita para esquerda e esquerda para direita O(nlogn)
//sol2 = encontrar elemento menor e maior fora de ordem mat[i-1] < mat[i] > mat[i+1]
//       iterate once again locating the positions that can be put those maior e menor elementos O(n)

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

pair<int,int> subarraySort(vector<int> a) {
    int smallest=INT_MAX, largest=INT_MIN;
    int n=a.size();
    
    if (a[0] > a[1]) {
            smallest=min(smallest, a[0]);
            largest=max(largest,a[0]);
    }

    if (a[n-2] > a[n-1]) {
            smallest=min(smallest, a[0]);
            largest=max(largest,a[0]);
    }

    cout << smallest << " " << largest << endl;

    for (int i=1;i<n-1;i++) {
        if (a[i-1] > a[i] || a[i] > a[i+1]) {
            //out of order
            smallest=min(smallest, a[i]);
            largest=max(largest,a[i]);
        }
    }
    cout << smallest << " " << largest << endl;

    if (smallest==INT_MAX) return {-1,-1};

    int min_pos=0, max_pos=n-1;
    
    for (int i=0;i<n;i++) {
        if (a[i] > smallest) {
            min_pos=i;
            break;
        }
    }

    for (int i=n-1;i>=0;i--) {
        if (a[i] < largest) {
            max_pos=i;
            break;
        }
    }
    return {min_pos,max_pos};
}

int main() {
    vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};

    auto p=subarraySort(arr);

    cout << p.first << " " << p.second << endl;

    return 0;
}