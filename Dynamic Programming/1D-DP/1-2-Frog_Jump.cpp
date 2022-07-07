//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// Top-down DP (Memoisation)
int solve(int i, vector<int> &heights, vector<int>&dp)
{
    if(i == 0) return 0;
    
    if(dp[i] != -1) return dp[i];
    
    int onestep = solve(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
    int twostep = INT_MAX;
    if(i > 1){
        twostep = solve(i-2, heights, dp) + abs(heights[i] - heights[i-2]);
    }
    return dp[i] = min(onestep, twostep);
}
int frogJump(int n, vector<int> &heights)
{
     vector<int>dp(n, -1);
     return solve(n-1, heights, dp);
}

// Bottom up (Tabulation)
int frogJump_Tabulation(int n, vector<int> &heights)
{
    vector<int>dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i<n; i++)
    {
        int onestep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twostep = INT_MAX;
        if(i > 1){
            twostep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(onestep, twostep);
    }
    return dp[n - 1];
}

//Space optimisation
int frogJump_spaceOptimised(int n, vector<int> &heights)
{
    int cur, prev = 0, prev2;
    for (int i = 1; i<n; i++)
    {
        int onestep = prev + abs(heights[i] - heights[i - 1]);
        int twostep = INT_MAX;
        if(i > 1){
            twostep = prev2 + abs(heights[i] - heights[i - 2]);
        }
        cur = min(onestep, twostep);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}