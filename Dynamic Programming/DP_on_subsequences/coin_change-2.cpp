// https://leetcode.com/problems/coin-change-2

#include <bits/stdc++.h>
using namespace std;

// Tabulation
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = (i % coins[0] == 0) ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = dp[i - 1][target];
            int take = 0;
            if (coins[i] <= target)
            {
                take = dp[i][target - coins[i]];
            }
            dp[i][target] = take + notTake;
        }
    }
    return dp[n - 1][amount];
}

//Memoised
int solve(vector<int> &coins, int target, int i, vector<vector<int>> &dp)
{

    if (i == 0)
    {   // If coins[i] is multiple of target than we can make any number of demominations
        // So there will be a combination 
        return (target % coins[i]) == 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    int notTake = solve(coins, target, i - 1, dp);
    int take = 0;
    if (coins[i] <= target)
    {
        take = solve(coins, target - coins[i], i, dp);
    }
    return dp[i][target] = take + notTake;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return solve(coins, amount, n - 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}