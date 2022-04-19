//divide and conquer
//nLogn, até max de N^2

//1 - choose a pivot (any element) = ex,: always last elem
//2 - partition array in 2 parts / all elem < pivot | pivot | all elem > pivot
//3 - recursivelly sort elem smaller than pivot and greater than pivot

#include <iostream>
#include <vector>

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
void quicksort(vector<int> &a, int s, int e) {
    //base case
    if (s>=e) return; //1 or less element

    //recursive case
    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main() {
    vector<int> arr{10,5,2,0,7,6,4};
    int n=arr.size();

    quicksort(arr,0,n-1);
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
