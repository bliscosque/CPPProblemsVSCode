//given 2 strings (big and small), find smallest windows in big str that contains all char of small str
//- windows can have additional char
//- if small has duplicates, those must be present in big
//input: hello_world / lol
//output: llo
///input: fizzbuzz / fuzz
//output: fizzbu

//a) build a frequency map of small (var,quantidade)
//b) mantain hashmap of current window
//c) expand - until containing all required words
//d) contract - remove unnecessary char from right

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string stringWindow(string big, string small) {
    //using array instead of hashmap
    vector<int> freq_small(256,0);
    vector<int> freq_str(256,0);
    int count=0; //how much char are matched
    int start=0;
    int start_idx=-1;
    int min_so_far=INT_MAX;
    int window_size;



    for (int i = 0; i < small.length(); i++) {
        freq_small[small[i]]++;   
    }


    for (int i = 0; i < big.length(); i++)
    {
        char ch=big[i];
        //expanding current windows - including current char
        freq_str[ch]++;

        //count how many char have been matched until now (string and small(pattern))
        if (freq_small[ch]!=0 && freq_str[ch] <= freq_small[ch]) {
            count++;
        }

        //if all char os small were found in current window, can start contraction
        if (count==small.length()) {
            //start removing from left unwanted char (1 - not present in small / 2 - freq is > required)
            while (freq_small[big[start]]==0 || freq_str[big[start]]>freq_small[big[start]]) {
                freq_str[big[start]]++;
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

    if (start_idx==-1) return "No window found";

    cout << start_idx << " " << min_so_far << endl;
    
    return big.substr(start_idx,min_so_far);
    

}

int main() {
    cout << stringWindow("hello_world","lol") << endl;
    cout << stringWindow("fizzbuzz","fuzz") << endl;
    
    return 0;
}