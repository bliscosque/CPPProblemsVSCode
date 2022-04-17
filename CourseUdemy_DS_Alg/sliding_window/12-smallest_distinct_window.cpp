#include<string>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

string smallestWindow(string str){
    
    //using array instead of hashmap
    vector<int> freq_pattern(256,0); //for this case, it should contain one of each var
    vector<int> freq_str(256,0);
    int count=0; //how much char are matched
    int start=0;
    int start_idx=-1;
    int min_so_far=INT_MAX;
    int window_size;
    int pattern_amt=0;



    for (int i = 0; i < str.length(); i++) {
        freq_pattern[str[i]]=1; //not counting... only putting as "1"   
    }
    for (int i = 0; i < 256; i++) {
        if (freq_pattern[i]) pattern_amt++; //counting amt of distinct letters   
    }

    for (int i = 0; i < str.length(); i++)
    {
        //cout << "main for: " << i << endl;
        char ch=str[i];
        //expanding current windows - including current char
        freq_str[ch]++;

        //count how many char have been matched until now (string and small(pattern))
        if (freq_pattern[ch]!=0 && freq_str[ch] <= freq_pattern[ch]) {
            count++;
            //cout << "incrementing count: " << count << endl;
        }

        //if all char os small were found in current window, can start contraction
        if (count==pattern_amt) {
            //cout << "Count==small" << endl;
            //start removing from left unwanted char (1 - not present in small / 2 - freq is > required)
            while (freq_pattern[str[start]]==0 || freq_str[str[start]]>freq_pattern[str[start]]) {
                freq_str[str[start]]--;
                start++;
            }

            //note the windows size
            window_size=i-start+1;
            if (window_size < min_so_far) {
                min_so_far=window_size;
                start_idx=start;
            }
        }
    }

    if (start_idx==-1) return "";

    //cout << start_idx << " " << min_so_far << endl;
    
    return str.substr(start_idx,min_so_far);
    
}

int main() {

    cout << smallestWindow("aabcbcdbcaaad") << endl;
    cout << smallestWindow("aaaa") << endl;
    return 0;
}