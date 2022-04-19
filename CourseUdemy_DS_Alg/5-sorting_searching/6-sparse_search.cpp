//given sort array of strings, interspersed with "" (empty str), write a method to find a location of a given str
//input={"ai","","","bat","","","car","cat","","","dog",""}
//bat
//output=4

//modified version of binary search

//after each middle, if mid is "", transverse in both direction from mid, until get valid string
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int sparce_search(vector<string> a, int n, string key) {
    int s=0;
    int e=n-1;
    while (s<=e) {
        int mid=(s+e)/2;
        cout << "mid: " << mid << endl;
        int mid_left=mid-1;
        int mid_right=mid+1;
        if (a[mid]=="") {
            //update mid to nearest non empty str
            while(1) {
                if (mid_left < s && mid_right > e)
                    return -1;
                else if (mid_right <=e && a[mid_right] != "") {
                    mid=mid_right;
                    break;
                }
                else if (mid_left >=s && a[mid_left] != "") {
                    mid=mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }

        }
        if (a[mid]==key) {
            return mid;
        }
        else if(a[mid] > key) {
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return -1;
}


int main() {
    vector<string> input={"ai","","","bat","","","car","cat","","","dog",""};
    int n=input.size();

    cout << sparce_search(input,n,"dog") << endl;
    return 0;
}