//you are given a running stream of integers. 
//Write efficient alg to output median of numers read so far after every input.

//input={10,5,2,3,0,12,18,20,22}

//10,7.5,5,4,3,4,5,7.5,10

//median = elemento do meio do array ordenado ou, caso tenha numero par de elementos, media dos 2 centrais

// obs: se adicionar 2 elementos maiores que a mediana, a mediana sera o proximo elemento. 
// Se adicionar 2 elementos menores que a mediana, a mediana sera o elemento anterior

//manter 2 heaps, por exemplo {1,2,3},5,{8,10,12} -> para os primeiros, um max heap, para os ultimos, um min heap
//cada um dos heaps deve conter numero igual de elementos. Caso seja impar, uma das 2 tem 1 elemento a mais ou a menos

#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> leftheap; //max
    priority_queue<int, vector<int>,greater<int>> rightheap; //minheap

    vector<int> vi={10,5,2,3,0,12,18,20,22};
    leftheap.push(vi[0]);
    float med = vi[0];
    cout << med << " ";
    for (int i=1;i<vi.size();i++) {
        int d=vi[i];
        if (leftheap.size() > rightheap.size()) {
            if (d < med) {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else {
                rightheap.push(d);
            }
            med=(leftheap.top()+rightheap.top())/2.0;
        }
        else if (leftheap.size()==rightheap.size()) {
            if (d<med) {
                leftheap.push(d);
                med=leftheap.top();
            }
            else {
                rightheap.push(d);
                med=rightheap.top();
            }
        }
        else {
            if (d<med) {
                leftheap.push(d);
            }
            else {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            med=(leftheap.top()+rightheap.top())/2.0;
        }
        cout << med << " ";
    }

    return 0;
}