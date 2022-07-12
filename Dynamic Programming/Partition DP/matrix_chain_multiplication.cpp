//

#include<bits/stdc++.h>
using namespace std;

//Tabulation
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N));

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mn = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = ((arr[i - 1] * arr[k] * arr[j]) +
                             dp[i][k] + dp[k + 1][j]);
                mn = min(mn, steps);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][N - 1];
}

// memoisation -> Time = O(N^3)
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j) // Only 1 matrix --> no multiplication possible
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}

int matrixChainMulti(vector<int> & arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N - 1, arr, dp);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}