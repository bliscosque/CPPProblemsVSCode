#include<vector>
#include<iostream>
using namespace std;

//Hint: DNF
//https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int n=balls.size();
    int low=0,mid=0,high=n-1;

    while(mid<=high) {
        if (balls[mid]==0) {
            swap(balls[low],balls[mid]);
            low++;
            mid++;
        }
        
        else if (balls[mid]==1) {
            mid++;
        }
        else { //balls[mid]==2
            swap(balls[mid],balls[high]);
            high--;
        }
    }
        
    
    return balls;
}

int main() {
    vector<int> input={0,0,1,2,0,1,2,0};
    vector<int> ans=sortBalls(input);
    for (auto i: ans) {
        cout << i << " ";
    }
}