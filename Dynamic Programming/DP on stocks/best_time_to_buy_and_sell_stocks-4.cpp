// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>
using namespace std;

// Memoisation O(N*2*K) time, space = O(N*2K)
// Another approach
int solve(vector<int> &prices, int i, int transactions, vector<vector<int>> &dp)
{
    if (i == prices.size() or transactions == 0)
        return 0;

    if (dp[i][transactions] != -1)
        return dp[i][transactions];

    int profit = 0;
    if (transactions % 2 == 0)
    {
        profit = max(-prices[i] + solve(prices, i + 1, transactions - 1, dp),
                     0 + solve(prices, i + 1, transactions, dp));
    }
    else
    {
        // K-1 means one transaction performed
        profit = max(prices[i] + solve(prices, i + 1, transactions - 1, dp),
                     0 + solve(prices, i + 1, transactions, dp));
    }
    return dp[i][transactions] = profit;
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    // k means Maximum number of transactions allowed
    int buy = 1; // Status that defines, we are ready to buy a stock

    vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));

    return solve(prices, 0, 2 * k, dp);
}


// Memoisation O(N*2*K) time
int solve(vector<int> &prices, int i, int buy, int k, vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 0;
    if (i == prices.size())
        return 0;

    if (dp[i][buy][k] != -1)
        return dp[i][buy][k];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(prices, i + 1, 0, k, dp),
                     0 + solve(prices, i + 1, 1, k, dp));
    }
    else
    {
        // K-1 means one transaction performed
        profit = max(prices[i] + solve(prices, i + 1, 1, k - 1, dp),
                     0 + solve(prices, i + 1, 0, k, dp));
    }
    return dp[i][buy][k] = profit;
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    // k means Maximum number of transactions allowed
    int buy = 1; // Status that defines, we are ready to buy a stock

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

    return solve(prices, 0, buy, k, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}