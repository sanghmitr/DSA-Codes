//https://leetcode.com/problems/longest-repeating-character-replacement/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int ans = INT_MIN;
        
        int i = 0, j = 0, maxfreq = 0;
        int n = s.length();
        while(j < n)
        {
            mp[s[j]]++;
            
            maxfreq = max(maxfreq, mp[s[j]]);
            if((j-i+1) - maxfreq > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str = "AABABBA";
    int k = 1;

    Solution s;
    cout<<s.characterReplacement(str, k);
    return 0;
}
