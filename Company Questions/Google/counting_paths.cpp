#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int m, int n, vector<vector<int>> &dp, int sum)
{
    if (i >= m or j >= n)
        return 0;

    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }
    if (dp[i][j] != 0)
        return dp[i][j];

    int down = 0, right = 0;
    down = solve(i + 1, j, m, n, dp, sum + );
    right = solve(i, j + 1, m, n, dp, sum);

    return dp[i][j] = down + right;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return solve(0, 0, m, n, dp, 0);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}