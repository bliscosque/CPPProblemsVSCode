#include <iostream>
#include<string>
using namespace std;

int main() {
    string paragraph="We are learning about STL strings. STL string class is quite powerful";

    string word;
    getline(cin,word);

    size_t index = paragraph.find(word);
    if (index==-1) {
        cout << "string not found" << endl;
    }
    else {
        cout << "index: " << index << endl;
        index=paragraph.find(word,index+1);
        cout << "next ocurrence: " << index << endl;
    }
    return 0;
}