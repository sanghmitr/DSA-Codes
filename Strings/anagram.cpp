#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b){
    unordered_map<char, int>mp;
    for(auto c : a)
        mp[c]++;
    
    for(auto c : b)
    {
        if(mp.find(c) == mp.end())
            return false;
        else
        {
            if(mp[c] > 0)
                mp[c]--;
                
            if(mp[c] == 0)
                mp.erase(c);
        }
    }
    return mp.empty();
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a = "GeeksforGeeks";
    string b = "forGeeksGeeks";

    cout<<isAnagram(a, b);
    return 0;
}