//giving ladder containing N steps
//can jump 1,2,3 at each step
//find number of ways to climb
//N=4
//output=7

//O(3^N)-> 3 chamadas em cada recursao

#include <iostream>
using namespace std;

int countWays(int n) {
    if (n<0) return 0;
    if (n==0) return 1;

    return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main() {
    int n=4;
    cout << countWays(n) << endl;
}