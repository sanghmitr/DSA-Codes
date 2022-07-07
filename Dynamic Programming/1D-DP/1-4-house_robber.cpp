// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

vector<int> dp; // Memoisation
int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int robbed = nums[i] + solve(nums, i + 2, dp);
    int skipped = solve(nums, i + 1, dp);
    return dp[i] = max(robbed, skipped);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    dp.resize(n, -1);
    return solve(nums, 0, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}