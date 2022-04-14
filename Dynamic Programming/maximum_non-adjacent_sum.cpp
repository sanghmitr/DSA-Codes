/*
Find maximum sum in the array that no two elements should be adjacent.
input = {6,10,12,7,9,14}
ans = 32 ----> {6 + 12 + 14}

*/

// https://leetcode.com/problems/house-robber

#include<bits/stdc++.h>
using namespace std;

int maxNonAdjacentSum(vector<int>&nums)
{
    int n = nums.size();
    vector<int>dp(n, 0);
    dp[0] = nums[0];

    //Corner cases
    if(n == 1)
        return max(nums[0], 0);
    else if(n == 2)
        return max({0, nums[0], nums[1]});

    for(int i=1;i<n;i++)
    {
        if(i >= 2)
        {
            dp[i] = max(dp[i], nums[i] + dp[i-2]);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    return dp[n-1];
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>nums = {6,10};
    cout<<maxNonAdjacentSum(nums);
    return 0;
}