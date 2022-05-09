//fiven N ropes each having different size, your task is join the ropes together.
//cost of joining 2 ropes: x+y
//find min cost to join all ropes together

//n=4
//ropes={4,3,2,6}

//29

//4+3=7
//7+2=9
//9+6=15

//7+9+15=31

//2+3=5
//5+4=9

//9+6=29 (minimun cost)

//greed -> join smaller cost first

//min heap alg
//1) add all elem in the min heap
//2) pick the smallest pair, join them and add their cost
//3) add the new rope in min heap
//repeat until single rope is left

#include <iostream>
#include <queue>
using namespace std;

int join_ropes(vector<int> ropes) {
    int n=ropes.size();
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes.begin(),ropes.end());

    int cost=0;
    while (min_heap.size()>1) {
        int A=min_heap.top();
        min_heap.pop();
        A+=min_heap.top();
        min_heap.pop();
        cost+=A;
        min_heap.push(A);
    }
    return cost;
 
}

int main() {
    vector<int> ropes={4,3,2,6};
    cout << join_ropes(ropes) << endl;
}