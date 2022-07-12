// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>
using namespace std;

//Greedy
int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        if (prices[i] - prices[i - 1] > 0)
            ans += prices[i] - prices[i - 1];
    }
    return ans;
}

// Memoisation 
int solve(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(prices, i + 1, 0, dp),
                     0 + solve(prices, i + 1, 1, dp));
    }
    else
    {
        profit = max(prices[i] + solve(prices, i + 1, 1, dp),
                     0 + solve(prices, i + 1, 0, dp));
    }
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}