#include <bits/stdc++.h>
using namespace std;
/*abc -> "", a,b,c,ab,ac,bc,abc -> 8 opcoes */


void findSubsets(char *input, char *output, int i, int j) {
    //base case
    if (input[i]=='\0') {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    //rec case
    //include the ith letter
    output[j] = input[i];
    findSubsets(input,output,i+1,j+i);
    //exclude the ith letter
    //overwriting
    findSubsets(input,output,i+1,j);
}

int main() {
    char input[100];
    char output[100];
    cin >> input;
    findSubsets(input,output,0,0);
    return 0;
}