// https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;


// 1D DP
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 0;

    for (int j = 1; j <= amount; ++j)
    {
        dp[j] = 1e9;
        for (int i = 0; i < coins.size(); ++i)
        {
            if (coins[i] <= j)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    return dp[amount] >= 1e9 ? -1 : dp[amount];
}

//Tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // int ans = minCoins(coins, amount, n-1, dp);

    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
        {
            dp[0][t] = t / coins[0];
        }
        else
        {
            dp[0][t] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            int notTake = dp[i - 1][t];
            int take = INT_MAX;
            if (coins[i] <= t)
            {
                take = 1 + dp[i][t - coins[i]];
            }
            dp[i][t] = min(take, notTake);
        }
    }

    if (dp[n - 1][amount] >= 1e9)
        return -1;
    return dp[n - 1][amount];
}
//Memoisation
int minCoins(vector<int> &coins, int amount, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (amount % coins[i] == 0)
        {
            return amount / coins[i];
        }
        else
            return 1e9;
    }

    if (dp[i][amount] != -1)
        return dp[i][amount];

    int take = INT_MAX;
    int notTake = minCoins(coins, amount, i - 1, dp);

    if (coins[i] <= amount)
    {
        take = 1 + minCoins(coins, amount - coins[i], i, dp);
    }
    return dp[i][amount] = min(take, notTake);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = minCoins(coins, amount, n - 1, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}