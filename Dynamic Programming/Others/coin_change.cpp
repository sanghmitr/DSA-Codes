
#include<bits/stdc++.h>
using namespace std;

// Find minimum number of coins required to make change for a given amount
// Top-down Recursive
int minCoinsRequired_recursive(int amount, vector<int>&coins) {
    if(amount == 0)
        return 0;
    
    int ans = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        if(amount >= coins[i])
        {
            ans = min(ans, minCoinsRequired_recursive(amount - coins[i], coins) + 1);
        }
    }
    return ans;
}

// Top-down with memoisation
int minCoinsRequired_memoisation(int amount, vector<int>&coins, vector<int>&dp) {
    if(amount == 0)
        return 0;
    
    if(dp[amount] != -1)
        return dp[amount];

    int ans = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        if(amount >= coins[i])
        {
            ans = min(ans, minCoinsRequired_memoisation(amount - coins[i], coins, dp) + 1);
        }
    }
    dp[amount] = ans;
    return ans;
}

// Bottom-up Tabulation
int minCoinsRequired_tabulation(int amount, vector<int>&coins)
{
    vector<int>dp(amount+1, 0);
    dp[0] = 0;

    for(int i=1; i<=amount; i++)
    {
        dp[i] = INT_MAX;
        for(auto coin : coins)
        {
            if(i - coin >= 0 and dp[i-coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main() {
    vector<int> coins = {1, 3, 7, 10};
    int amount = 15;
    cout << minCoinsRequired_recursive(amount, coins) << endl;

    vector<int>dp1(amount+1, -1);
    cout<< minCoinsRequired_memoisation(amount, coins, dp1)<<endl;
    cout << minCoinsRequired_tabulation(amount, coins) << endl;
    return 0;
}
