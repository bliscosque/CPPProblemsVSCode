//given array, count total inversions
//a[i] and a[j] form inversion if a[i]>a[j] && i<j
//ex: a={0,5,2,3,1}
//count: 5
// 5 2
// 5 3
// 5 1
// 2 1
// 3 1

// 1) brute force: comparing all elem i with elements that comes after O(N^2)
// 2) calculate how many inversions each elem will form (divide & conquer) - O(nlogN) --- igual merge sort
//    c1= 0,5,2 = 1 inversion (5,2)
//    c2= 3,1   = 1 inversion (2,1)
//    cross inversion (ci)=5,3     5,1      2,1
// total=c1+c2+ci
//    calcular ci é basicamente calcular quantas inversoes há no merge sort (na parte do merge)


#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &array, int s, int e) {
    //1 part from start to mid, another from mid+1 to end
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    int cnt=0;

    vector<int> temp;
    while (i<=m && j<=e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        }else {
            temp.push_back(array[j]);
            cnt+=m-i+1; //conta todos os elementos que sao menores
            j++;
        }
    }
    //this previoous loop will break when one of the subarrays exhausted

    //copy remaining elements from first or second array
    while (i<=m) {
        temp.push_back(array[i++]);
    }
    while (j<=e) {
        temp.push_back(array[j++]);
    }

    //copy back elements from temp to original array
    int k=0;
    for (int idx=s;idx<=e;idx++) {
        array[idx]=temp[k++];
    }
    return cnt;
}

int count_inversion(vector<int> &array, int s, int e) {
    //base case
    if (s>=e) { //max of 1 elem
        return 0;
    }

    //rec case
    int mid=(s+e)/2;
    int c1=count_inversion(array,s,mid);
    int c2=count_inversion(array, mid+1,e);
    int ci=merge(array, s, e);
    return c1+c2+ci;
}

int main() {

    vector<int> arr{0,5,2,3,1};
    int s=0; //start
    int e=arr.size()-1; //end
    cout << count_inversion(arr,s,e) << endl;
    

    return 0;
}