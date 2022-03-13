#include<bits/stdc++.h>
using namespace std;

string remove_duplicates(string s){
    
    if(s.length() == 0)
        return s;
    string res = "";
    int i=0;
    while(i<s.length())
    {
        char ch = s[i];
        int freq = 0;
        while(i < s.length() and ch == s[i])
        {
            freq++;
            i++;
        }
        if(freq == 1) 
            res += ch;
        
        if(res == s)
            return res;
    }
    return remove_duplicates(res);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "DBAABDAB";
    cout<<"Original string : "<<s<<endl<<"Reduced : "<<remove_duplicates(s)<<endl;
    return 0;
}

