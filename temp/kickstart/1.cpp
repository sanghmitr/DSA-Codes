#include<bits/stdc++.h>
using namespace std;

string solve(string I, string P)
{
    unordered_map<char, int>mp;
    unordered_map<char, int>mp1;
        int ans = 0;
        for(auto c : I)
        {
            mp[c]++;
        }
        
        for(auto c : P)
        {
            mp1[c]++;
        }
        for(auto p : mp)
        {
            int key = p.first;
            if(mp1.find(key) == mp1.end())
                return "IMPOSSIBLE";
            else
            {
                if(p.second > mp1[key])
                    return "IMPOSSIBLE";
                else
                {
                    ans += mp1[key] - p.second;
                }
            }
        }
        return to_string(ans);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        string I,P;
        cin>>I>>P;
        cout<<solve(I,P)<<endl;
    }
    return 0;
}