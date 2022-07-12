// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<bits/stdc++.h>
using namespace std;

//Tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int k = 2;   // Maximum number of transactions allowed
    int buy = 1; // Status that defines, we are ready to buy a stock

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[i + 1][0][cap],
                                 0 + dp[i + 1][1][cap]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][1][cap - 1],
                                 0 + dp[i + 1][0][cap]);
                }
                dp[i][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

//Memoisation O(N*2*3) time
int solve(vector<int>&prices, int i, int buy, int k, vector<vector<vector<int>>>&dp){
    if(k == 0) return 0;
    if(i == prices.size()) return 0;
    
    if(dp[i][buy][k] != -1) return dp[i][buy][k];
    
    int profit = 0;
    if(buy){
        profit = max(-prices[i] + solve(prices, i+1, 0, k, dp),
                    0 + solve(prices, i+1, 1, k, dp));
    }
    else{
        //K-1 means one transaction performed
        profit = max(prices[i] + solve(prices, i+1, 1, k-1, dp),
                        0 + solve(prices, i+1, 0, k, dp));
    }
    return dp[i][buy][k] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    int k = 2; //Maximum number of transactions allowed
    int buy = 1; // Status that defines, we are ready to buy a stock
    
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    
    return solve(prices, 0, buy, k, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}