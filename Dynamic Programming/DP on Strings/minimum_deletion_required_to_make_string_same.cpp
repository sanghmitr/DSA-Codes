// https://leetcode.com/problems/delete-operation-for-two-strings/

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m)
{
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
    return dp[n][m];
}

int minDistance(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int ans = 0;

    int temp = lcs(s1, s2, n, m);
    ans = n + m - (2 * temp);

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}