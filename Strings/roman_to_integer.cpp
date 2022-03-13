#include<bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
    // code here
    unordered_map<char, int>mp;
    mp.insert({'I',1});
    mp.insert({'V',5});
    mp.insert({'X',10});
    mp.insert({'L',50});
    mp.insert({'C',100});
    mp.insert({'D',500});
    mp.insert({'M',1000});
    
    int ans = 0;
    int i = str.length()-1;
    while(i >= 0)
    {
        if( i > 0 and mp[str[i]] > mp[str[i-1]])
        {
            ans += mp[str[i]];
            ans -= mp[str[i-1]];
            i -= 1;
        }
        else
            ans += mp[str[i]];
        i--;
    }
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "IMXC";
    cout<<romanToDecimal(s);
    return 0;
}