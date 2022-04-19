//return kth smallest element from the array
//a={10,5,2,0,7,6,4}
//k=4
//output=5

//use quick sort, but going only from right or left after each iteration

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &a, int s, int e) {
    int i=s-1;
    int pivot=a[e]; //last elem as pivot

    for (int j=s;j<e;j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]); //put pivot in right position
    return i+1; //return pivot position

}
int quickselect(vector<int> &a, int s, int e, int k) {
    int p=partition(a,s,e);
    //base case
    if (p==k) return a[p-1]; //1-index based element
    else if (k<p) return quickselect(a,s,p-1,k);
    else return quickselect(a,p+1,e,k);
}

int main() {
    vector<int> a={10,5,2,0,7,6,4};
    int k=4;
    cout << quickselect(a,0,a.size()-1,k) << endl;

    return 0;
}