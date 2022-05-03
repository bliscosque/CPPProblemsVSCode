//given array and k, maximum for each and every contiguous subarray of size k
//n=9
//arr[]={1,2,3,1,4,5,2,3,6}
//k=3
//output = 3,3,4,5,5,5,6
//max 1,2,3=3; max 2,3,1=3, etc

//deque vai manter apenas elementos "uteis" (menores elementos anteriores serao removidos)
//ex.; para 1,2,3 -> insere 1, insere 2 (1 eh inutil, apagar 1), inserir 3 (apagar 2, inutil)
//remover tambem elementos outside of the k elementos verificados até o momento

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSubArray(vector<int> a, int k) {

    //1. processar k primeiros elementos
    deque<int> dq(k);
    int i;
    int n=a.size();
    for (i=0;i<k;i++) {
        //remove elementos inuteis
        while (!dq.empty() && a[i] > a[dq.back()]) {
            dq.pop_back();
        }
        //insere novo elemento
        dq.push_back(i);
    }

    //2. outros elementos
    for (;i<n;i++) {
        cout << a[dq.front()] << " ";
        //remove elements from the left (contraction - elements outside current window)
        while(!dq.empty() && dq.front() <=i-k) {
            dq.pop_front();
        }
        //remove elementos inuteis
        while (!dq.empty() && a[i] > a[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    cout << a[dq.front()] << " ";

}

int main() {
    vector<int> arr={1,2,3,1,4,5,2,3,6};
    int k=3;
    
    maxSubArray(arr,k);

    return 0;
}
