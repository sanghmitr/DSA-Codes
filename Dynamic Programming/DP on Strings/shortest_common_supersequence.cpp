// https://leetcode.com/problems/shortest-common-supersequence

#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int reslen = dp[n][m];
    // int idx = reslen-1;
    string ans = "";

    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = s1[i - 1] + ans;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans = s1[i - 1] + ans;
            i--;
        }
        else
        {
            ans = s2[j - 1] + ans;
            j--;
        }
    }
    // cout<<ans;
    while (i > 0)
    {
        ans = s1[i - 1] + ans;
        i--;
    }

    while (j > 0)
    {
        ans = s2[j - 1] + ans;
        j--;
    }
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
