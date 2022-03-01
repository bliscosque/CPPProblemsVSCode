#include<bits/stdc++.h>
using namespace std;

//solution provided in https://ide.codingminutes.com/?id=kps and 
// https://github.com/apaarkamal/Coding-Minutes-Competitive-Programming/blob/main/Coding%20Exercise%20Solutions/Shortest%20Superstring.cpp
// https://www.youtube.com/watch?v=6LpQOyiPxY0

//Travelling salesman problem 
//cost moving from one string to another is nonoverlapping string between them
int n;
string solve(int pos,int val,vector<vector<string>>&dp,vector<vector<string>>&v)
{
    //val=0 means 000
    //that means it is state when all strings are used
    //so it is the base case & we are returning from here
    if(val==0)
    {
        return "";
    }

    //this is condition to reduce recomputations of same state
    //we are using recursion 
    //so same state can occur again
    if(dp[pos][val].size()!=0)
    {
        return dp[pos][val];
    }


    //here making calls to subcases through recursion
    string ans="";
    for(int i=0;i<n;i++)
    {
        int val1=1<<i;
        if(val&val1)
        {
            string str=v[pos][i]+solve(i,val^val1,dp,v);
            if(ans.size())
            {
                ans=ans.size()>str.size()?str:ans;
            }
            else{
                ans=str;
            }
        }
    }
    return dp[pos][val]=ans;
}
string shortestSuperstring(vector<string> words) {
    //finding no. of words available
    n=words.size();

    //this vector of vectors will store nonoverlapping string between two words
    //v[i][j] will contain nonoverlapping portion of jth word where ith word is starting word and jth word is overlapped on it
    vector<vector<string>>v(n,vector<string>(n,""));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            string str=words[j];
            for(int k=0;k<words[i].size();k++)
            {
                string str1,str2;
                str1=words[i].substr(k);
                for(int k1=1;k1<=words[j].size();k1++)
                {
                    str2=words[j].substr(0,k1);
                    if(str1==str2)
                    {
                        str=words[j].substr(k1);
                        goto x;
                    }
                }
            }
            x:;
            v[i][j]=str;
        }
    }
    //if words={"abc","bcd","carb"}
    //then vector v will contain following result
    //{{""    , "d"  , "arb"  },
    // {"abc" , ""   , "carb" },
    // {"abc" , "cd" , ""     }}



    //ans variable will store final result
    string ans;

    //we are using this val to maintain state of string
    //state of string means which word is included till now
    //which word is not included yet
    //binary representation of val will help us to determeine state
    //ith bit of val will tell wether ith word is included in answer string or not
    //for eg we were having 3 words
    //then val=2^3-1
    //val=7
    //7= 111
    //if ith bit is 1 that means ith word is not included
    //if ith bit is 0 that means ith word is included in answer string
    //Initially no word is included so 111 is the state
    int val=1<<n;
    val--;


    //this dp vector will store best answer for particular state when starting word is fixed
    vector<vector<string>>dp(n,vector<string>(val,""));

    //this loop will iterate n times 
    //and it will fix every word at first position and try to compute answer
    //if that answer is best 
    //then it will be updated as final answer till more better option isn't available
    //we will recursively use this technique to find best result
    for(int i=0;i<n;i++)
    {
        string str=words[i];
        //here making call to find answer when ith word is fixed at first place
        str+=solve(i,val^(1<<i),dp,v);
        if(ans.size())
        {
            ans=ans.size()>str.size()?str:ans;
        }
        else{
            ans=str;
        }
    }   
    return ans;
}

int main() {
    vector<string> words = {"catg", "ctaag", "gcta", "ttca", "atgcatc"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}