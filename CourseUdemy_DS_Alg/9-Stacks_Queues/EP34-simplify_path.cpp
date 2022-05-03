//working only for absolute paths

#include<vector>
#include<string>
#include<sstream>
#include <iostream>
#include<deque>
using namespace std;


string simplifyPath(string path){
   istringstream iss(path);
   vector<string> tokens;
   deque<string> dq;
   string token;

   while (getline(iss,token,'/')) {
       if (token=="" || token==".") continue;
       else if (token=="..") {
           if (!dq.empty()) {
               dq.pop_back();
           }
       }
       else {
           dq.push_back(token);
       }
   }
   string ans="";
   for (auto str:dq) {
       cout << "/" << str;
        ans+="/"+str;
   }   
   return ans;
}

int main() {
    string path="/../x/y/../z/././w/a///../../c/./";
    simplifyPath(path);

    return 0;
}