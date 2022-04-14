//https://leetcode.com/problems/decode-ways

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[0] = 1;

        if (s[0] != '0') 
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] > '0') 
                dp[i] = dp[i - 1];
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) 
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};