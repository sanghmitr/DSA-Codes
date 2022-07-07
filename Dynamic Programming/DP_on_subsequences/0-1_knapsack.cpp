#include<bits/stdc++.h>
using namespace std;
     

//space optimised
int knapsack_spaceOpt(vector<int>&wt, vector<int>val, int n, int capacity){
    vector<int> prev(capacity + 1, 0);

    for (int w = wt[0]; w <= capacity; w++){
        prev[w] = val[0];
    }

    for (int i = 1; i<n; i++){
        vector<int> cur(capacity + 1, 0);
        for (int w = 0; w <= capacity; w++){
            int take = INT_MIN;
            int notTake = prev[w];

            if(wt[i] <= w){
                take = val[i] + prev[w - wt[i]];
            }
            cur[w] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[capacity];
}
//Tabulation
int knapsack(vector<int> wt, vector<int> val, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int W = wt[0]; W <= capacity; W++)
    {
        dp[0][W] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int take = INT_MIN;
            int notTake = dp[i - 1][w];

            if (wt[i] <= w)
            {
                take = val[i] + dp[i - 1][w - wt[i]];
            }
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n - 1][capacity];
}

//Memoised solution // Time complexity = O(N*Capacity) , where N = number of weights, W = capacity of the bag
// space = O(N*W) + O(N) ... Recursion Stack space extra, 
int knapsack01(vector<int> &weights, vector<int> &values, int capacity, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weights[i] <= capacity)
        {
            return values[i];
        }
        return 0;
    }

    if (dp[i][capacity] != -1)
        return dp[i][capacity];

    int take = INT_MIN;
    int notTake = knapsack01(weights, values, capacity, i - 1, dp);
    if (weights[i] <= capacity)
    {
        take = values[i] + knapsack01(weights, values, capacity - weights[i], i - 1, dp);
    }
    return dp[i][capacity] = max(take, notTake);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}