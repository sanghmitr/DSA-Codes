// https://leetcode.com/problems/edit-distance

#include<bits/stdc++.h>
using namespace std;


//tabulation
int minDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int del = 1 + dp[i - 1][j];
                int add = 1 + dp[i][j - 1];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({del, add, replace});
            }
        }
    }
    return dp[n][m];
}

//Memoisation , time = O(n*m)
int lcs(string &s1, int n, string &s2, int m, vector<vector<int>> &dp)
{
    if (n < 0)
    {
        return m + 1; // if S1 get exhausted then we need to insert m+1 characters to make it equal to s2.
    }

    if (m < 0)
    {
        return n + 1;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = 0;
    if (s1[n] == s2[m])
    {
        ans = lcs(s1, n - 1, s2, m - 1, dp);
    }
    else
    {
        int del = lcs(s1, n - 1, s2, m, dp);
        int insert = lcs(s1, n, s2, m - 1, dp);
        int replace = lcs(s1, n - 1, s2, m - 1, dp);
        ans = 1 + min({del, insert, replace});
    }
    return dp[n][m] = ans;
}
int minDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcs(s1, n - 1, s2, m - 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}