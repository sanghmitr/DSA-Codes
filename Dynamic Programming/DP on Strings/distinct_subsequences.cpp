// https://leetcode.com/problems/distinct-subsequences

#include<bits/stdc++.h>
using namespace std;

int numDistinct_tabulation(string &s, string &t){
    int n = s.length();
    int m = t.length();

    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return (int)dp[n][m];
}

//Memoisation
int solve(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    if (m < 0)
        return 1;
    if (n < 0 and m >= 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = 0;
    if (s[n] == t[m])
    {
        ans = solve(s, t, n - 1, m - 1, dp) + solve(s, t, n - 1, m, dp);
    }
    else
    {
        ans = solve(s, t, n - 1, m, dp);
    }
    return dp[n][m] = ans;
}

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s, t, n - 1, m - 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}