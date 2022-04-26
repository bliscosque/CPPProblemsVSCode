#include<bits/stdc++.h>
using namespace std;

bool minPagesPossible(vector<int> books, int m,int mid) {
    int curr_stud=0;
    int students=1;
    int n=books.size();

    for(int i=0;i<n;i++) {
        if (curr_stud + books[i] >mid) {
            students++;
            curr_stud=books[i];
            if (students > m) return false;
        }
        else {
            curr_stud+=books[i];
        }
    }
    return true;
}


int minPages(vector<int> books, int m){
    int s=0;
    //max is the sum of all books
    int e=0;
    int mid;
    int ans=INT_MAX;
    for (auto el:books) {
        e+=el;
        s=max(s,el);
    }

    //binary search
    while (s<=e) {
        mid=(s+e)/2;
        //cout << "trying: " << mid << endl;
        bool isPossible=minPagesPossible(books,m,mid);
        //cout << "res: " << isPossible << endl;
        if (isPossible) {
            ans=min(ans,mid);
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> books={10,20,30,15}; //45 (10,20),(30,15)
    int students=2;

    cout << minPages(books, students) << endl;

    return 0;
}