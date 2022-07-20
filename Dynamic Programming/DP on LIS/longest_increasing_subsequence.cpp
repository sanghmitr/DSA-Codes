// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

// Space optimisation with O(N*N) time 
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();

    vector<int>dp(n, 1);
    int len = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}
// Tabulation
int lengthOfLIS(vector<int>&nums){
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--){
        for (int prev = i - 1; prev >= -1; prev--){
            int len = 0 + dp[i + 1][prev + 1]; // +1 added to prev beacause of index shift
            if(prev == -1 or nums[i] > nums[prev]){
                len = 1 + dp[i + 1][i + 1];
            }
            dp[i][prev + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

    // Memoisation
    int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
{
    if(i >= nums.size()) return 0;
    
    if(dp[i][prev] != -1) return dp[i][prev];
    
    int take = 0, notTake = 0;
    if(prev == nums.size() or nums[i] > nums[prev]){
        take = 1 + solve(nums, i+1, i, dp);
    }
    notTake = 0 + solve(nums, i+1, prev, dp);
    return dp[i][prev] = max(take, notTake);
}

int lengthOfLIS(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    return solve(nums, 0, n, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}