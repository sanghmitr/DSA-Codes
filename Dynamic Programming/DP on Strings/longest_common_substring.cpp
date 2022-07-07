// 

#include <bits/stdc++.h>
using namespace std;

// Tabulation
int lcs_tabulation(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
// Memoisation
int lcs(string s1, int n, string s2, int m, vector<vector<int>> &dp)
{
    if (n < 0 or m < 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = 0;
    if (s1[n] == s2[m])
    {
        ans = 1 + lcs(s1, n - 1, s2, m - 1, dp);
    }
    else
    {
        ans = 0;
        //ans = max(lcs(s1, n - 1, s2, m, dp), lcs(s1, n, s2, m - 1, dp));
    }
    return dp[n][m] = ans;
}
int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcs(s1, n - 1, s2, m - 1, dp);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << lcs_tabulation("abcde", "abce");
    return 0;
}