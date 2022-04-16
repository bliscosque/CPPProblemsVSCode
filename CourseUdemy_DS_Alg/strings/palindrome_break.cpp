/*
Case 1: For this the best thing you can do is to pick the leftmost element (Which should not be 'a' and 
change it to 'a').  You can iterate and find the first element which not 'a' and change it to 'a'.

Case 2: Now this is one case that strikes to us at first, now what if all the elements of the string are a, 
this approach wont work here. So if all elements of the string are 'a', pick the last element and change it 
to 'b'.

Case 3: Another case can be, if the string contains only 1 character, we can't make it not palindromic.

Case 4: One more case that should be handled is, if we get a string whose length is odd, if we are trying 
to use the approach in case 1, we should not try to modify the middle element as it won't make the string 
not palindromic., if we get the middle element as the first non 'a' element, find for the next non 'a' element 
and change it to 'a', again if rest all elements are 'a', change the last element to 'b'.

*/

#include <string>
#include <iostream>
using namespace std;

string breakPalindrome(string palindrome) {
    //case 3
    if (palindrome.length() == 1) return "";
    //case 2
    bool allA=true;
    for (char ch:palindrome) {
        if (ch!='a') allA=false;
    }
    if (allA) {
        palindrome[palindrome.length()-1]='b';
        return palindrome;
    }
    //cases 1 and 4
    for(int i=0;i<palindrome.length();i++) {
        bool isOdd=(palindrome.length()%2==1);
        if (palindrome[i] !='a' && (!isOdd || (isOdd && i!=palindrome.length()/2))) {
            palindrome[i]='a';
            return palindrome;
        }
    }
    palindrome[palindrome.length()-1]='b';
    return palindrome;
        
}


int main() {
    cout << breakPalindrome("abccba") << endl;
    cout << breakPalindrome("a") << endl;
    cout << breakPalindrome("aa") << endl;
    cout << breakPalindrome("aba") << endl;

    return 0;
}