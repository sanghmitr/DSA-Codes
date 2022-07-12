// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int i, int buy, int fee, vector<vector<int>> &dp)
{
    if (i == prices.size())
    {
        return 0;
    }

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(prices, i + 1, 0, fee, dp),
                     0 + solve(prices, i + 1, 1, fee, dp));
    }
    else
    {
        profit = max(prices[i] - fee + solve(prices, i + 1, 1, fee, dp),
                     0 + solve(prices, i + 1, 0, fee, dp));
    }
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(prices, 0, 1, fee, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}