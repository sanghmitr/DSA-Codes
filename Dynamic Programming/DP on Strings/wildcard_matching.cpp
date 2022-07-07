// https://leetcode.com/problems/wildcard-matching

#include<bits/stdc++.h>
using namespace std;

bool solve(string &s, string &p, int n, int m, vector<vector<int>> &dp)
{

    // Base conditions
    if (n < 0 and m < 0)
        return true;
    if (n >= 0 and m < 0)
        return false;

    if (n < 0 and m >= 0)
    {
        // If there stills all "*" left then return true;
        for (int j = m; j >= 0; j--)
        {
            if (p[j] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    // Cases
    if (s[n] == p[m] or p[m] == '?')
    {
        return dp[n][m] = solve(s, p, n - 1, m - 1, dp);
    }
    else if (p[m] == '*')
    {
        return dp[n][m] = solve(s, p, n - 1, m, dp) or solve(s, p, n, m - 1, dp);
    }
    else
    {
        return dp[n][m] = false;
    }
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s, p, n - 1, m - 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

