#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(int a, int b) {
    //true = >
    cout << "comparing: " << a << " and " << b << ": " ;
    string sa=to_string(a);
    string sb=to_string(b);
    if (sa.length()==sb.length()) {
        for (int i=0;i<sa.length();i++) {
            if (sa[i] > sb[i]) {
                cout << "true" << endl;
                return true;
            }
            if (sa[i] < sb[i]) {
                cout << "false" << endl;
                return false;
            }
        }
        cout << "true" << endl;
        return true;
    }
    //different sizes
    int minsize=min(sa.length(),sb.length());
    for (int i=0;i<minsize;i++) {
        if (sa[i] > sb[i]) {
            cout << "true" << endl;
            return true;
        }
        if (sa[i] < sb[i]) {
            cout << "false" << endl;
            return false;
        }
    }
    if (sa.length() < sb.length()) {
        cout << "true" << endl;
        return true;
    }
    
    cout << "false" << endl;
    return false; 
    
}

string concatenate(vector<int> numbers){
    cout << "Input: " << endl;
    for (int i:numbers) cout << i <<",";
    cout << endl;

    string ans="";
    sort(numbers.begin(),numbers.end(),comp);
    for (int i:numbers) {
        ans+=to_string(i);
    }
    return ans;
}
int main() {
    //vector<int> numbers={10,11,20,30,3};
    //cout << concatenate(numbers) << endl;
    vector<int> numbers2={10,200,30,11,1,2,3};
    cout << concatenate(numbers2) << endl;
    return 0;
}
