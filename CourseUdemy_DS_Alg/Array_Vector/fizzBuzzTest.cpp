#include<vector>
#include<string>
#include<iostream>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    vector<string> ans;
    for (int i=1;i<=n;i++) {
        if (i%3==0 && i%5==0) {
            ans.push_back("FizzBuzz");
        }
        else if (i%3==0) {
            ans.push_back("Fizz");
        }
        else if (i%5==0) {
            ans.push_back("Buzz");
        }
        else ans.push_back(to_string(i));
    }
    return ans;
}

int main() {
    vector<string> ans = fizzbuzz(15);
    for (auto s:ans) {
        cout << s << " ";
    }
    return 0;
}