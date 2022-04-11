#include<vector>
#include<iostream>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);

    if (n==1) return {0};
    
    //percorrendo da esquerda para direita
    int temp=1;
    for (int i = 0; i < n; i++)
    {
        output[i]=temp; //todos com 1
        temp*=arr[i]; //tem a multiplicacao de todos os elementos
    }
    //percorrendo da direita para esquerda
    temp=1;
    for (int i = n-1; i >= 0; i--)
    {
        output[i]*=temp;
        temp*=arr[i];
    }
    
    return output;
}

int main() {
    vector<int> vi={1,2,3,4,5};
    vector<int> ans=productArray(vi);
    for (auto i:ans) {
        cout << i << " ";
    }

    return 0;
}