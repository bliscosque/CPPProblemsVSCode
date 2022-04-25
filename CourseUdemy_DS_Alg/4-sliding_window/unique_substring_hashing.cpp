//given string, find largest substring with unique char
//prateekbhaiya -> ekbhaiy
//aabcb -> abc

//1) brute force
//2) sliding windows
//   cur char is part of window -> start new windows from last position + 1
//   else expand current window
//   lookup -> unordered_map<char,int> --- last occurence of current char 

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string unique_substring(string str) {

    int i=0, j=0;
    int window_len=0;
    int max_window_len=0;
    int start_window=-1;
    unordered_map<char,int> m;

    while (j<str.length()) {
        char ch=str[j];

        //if its inside hashmap and idx >= start of current windows
        if (m.count(ch) && m[ch] >= i) {
            //start new window. Update len
            i = m[ch]+1;
            window_len= j-i; //updated remaining len excluding current char

        }

        //update last occurency
        m[ch] = j;
        window_len++;
        j++;

        //update max_windows_len at every step
        if (window_len > max_window_len) {
            max_window_len=window_len;
            start_window=i;
        }

    }
    return str.substr(start_window,max_window_len);

}

int main() {
    cout << unique_substring("prateekbhaiya") << endl;
    cout << unique_substring("aabcb") << endl;

    return 0;
}