#include<string>
#include<iostream>
using namespace std;

string convert_to_digital_time(int minutes){
    int h=minutes/60;
    string ans=to_string(h)+":";
    int m=minutes%60;
    if (m<10) ans+="0";
    ans+=to_string(m);
    return ans;
    
}

int main() {
    cout << convert_to_digital_time(125) << endl;
    cout << convert_to_digital_time(155) << endl;
    return 0;
}