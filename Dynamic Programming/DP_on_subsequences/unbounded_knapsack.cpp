// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029
#include<bits/stdc++.h>
using namespace std;

//Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = ((int)i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= w; target++)
        {
            int take = INT_MIN;
            int notTake = dp[i - 1][target];

            if (weight[i] <= target)
            {
                take = profit[i] + dp[i][target - weight[i]];
            }
            dp[i][target] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

//Memoisation
int solve(vector<int> &weight, vector<int> &profit, int w, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return ((int)(w / weight[i])) * profit[i];
    }

    if (dp[i][w] != -1)
        return dp[i][w];

    int notTake = solve(weight, profit, w, i - 1, dp);
    int take = INT_MIN;
    if (weight[i] <= w)
    {
        take = profit[i] + solve(weight, profit, w - weight[i], i, dp); // Stay at the same index for infinite time consideration
    }
    return dp[i][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(weight, profit, w, n - 1, dp);
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
