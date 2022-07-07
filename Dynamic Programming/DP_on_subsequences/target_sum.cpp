// https://leetcode.com/problems/target-sum

// Copy of Count partitions with given difference

#include<bits/stdc++.h>
using namespace std;

//Tabulation
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (auto &p : dp[i])
        {
            dp[i + 1][p.first + nums[i]] += p.second;
            dp[i + 1][p.first - nums[i]] += p.second;
        }
    }
    return dp[n][target];
}

// Memoised (TLE), time = O(N*S) where N = length of nums, S = Total sum of array elements
int find(vector<int> &nums, int target, int i, vector<unordered_map<int, int>> &dp)
{
    if (i == nums.size())
        return target == 0;

    if (dp[i].find(target) != dp[i].end())
    {
        return dp[i][target];
    }

    return find(nums, target + nums[i], i + 1, dp) + find(nums, target - nums[i], i + 1, dp);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n);
    return find(nums, target, 0, dp);
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}