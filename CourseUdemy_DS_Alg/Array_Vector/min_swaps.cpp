//given array, find minimun number of swaps needed to make the array sorted
//input={5,4,3,2,1}
//output=2
//input={10,11,5,4,3,2,1}
//output=4
//input={2,4,5,1,3}
//output=3

//we should know correct location of each element (need sorting)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int countMinSwaps(vector<int> arr) {
    int n=arr.size();
    int ans=0;
    //know the actual positions of elements (sorting) and store the current indices
    pair<int,int> ap[n];
    for (int i=0;i<n;i++) {
        ap[i].first=arr[i];
        ap[i].second=i;
    }

    //sorting
    sort(ap,ap+n);

    //main logic
    vector<bool> visited(n,false);
    for (int i=0;i<n;i++) {
        //if element is visited or element is in the right position
        int old_position=ap[i].second;
        if (visited[i] || old_position==i) continue;

        //visiting the element (index) for the first time
        int node=i;
        int cycle=0;
        while (!visited[node]) {
            visited[node]=true;
            int next_node=ap[node].second;
            node=next_node;
            cycle++;
        }
        ans+=(cycle-1);
    }

    return ans;
}


int main() {
    vector<int> arr={10,11,5,4,3,2,1};
    cout << countMinSwaps(arr) << endl;
    return 0;
}