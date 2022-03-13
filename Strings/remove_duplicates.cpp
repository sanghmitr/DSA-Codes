//https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1#

#include<bits/stdc++.h>
using namespace std;

string removeDups(string s) 
{
    char freq[26] = {0};
    int i = 0;
    for(auto c : s)
    {
        if(freq[c - 'a'] == 0)
        {
            freq[c - 'a']++;
            s[i] = c;
            i++;
        }
        else
        {
            s[i] = c;
        }
    }
    return s.substr(0,i);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "gfgggfa";
    cout<<removeDups(s);  //ans = gfa
    return 0;
}