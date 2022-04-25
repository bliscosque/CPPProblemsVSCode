//based on sliding window minimum. Description from USACO TRAINING:
//We mantain a queue where each element is smaller than the previous element, 
//   the first elem always correspond to the maximum
// After each window move, we remove elements from the end of the queue 
//   until last queue elem is greater than new window elem, or the queue become empty
//We also remove the first queue elem if it is not inside the window anymore
//Finally, we add the new window element to the end of the queue
#include<vector>
#include<iostream>
#include<deque>

using namespace std;


vector<int> maxInWindow(vector<int> input,int k){
    vector<int> ans;
    int n=input.size();
     
    deque<int> deq;

    //first k elemenents in the array (gerar queue com elementos decrescentes apenas, em ordem)

    int i;

    for(i=0;i<k;i++) {
        while(!deq.empty() && input[i] > input[deq.back()]) { //remove all elements greater than current one
            deq.pop_back();
        }
        deq.push_back(i); 
    }
    
    //remaining elem
    for(;i<n;i++) {
        ans.push_back(input[deq.front()]); //the maximum is always first elem of queue

        //remove elem from the left (contraction when an index lies outside the current window)
        while(!deq.empty() && deq.front() <= i-k) {
            deq.pop_front();
        }

        while(!deq.empty() && input[i] >= input[deq.back()]) { //remove all elements greater than current one
            deq.pop_back();
        }

        deq.push_back(i); 

    }

    ans.push_back(input[deq.front()]);

    return ans;
}

int main() {
    int k=3;
    vector<int> vi={1,2,3,1,4,5,2,3,6};
    vector<int> ans=maxInWindow(vi,k);
    for (auto i:ans) {
        cout << i <<" ";
    }
    cout << endl;
    return 0;
}