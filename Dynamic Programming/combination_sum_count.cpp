#include<bits/stdc++.h>
using namespace std;

// Count all combinations of given numbers that make up a target number
// using dynamic programming
int combinationSum(int target, vector<int>&nums)
{
    vector<int>dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=nums[i];j<=target;j++)
        {
            dp[j]+=dp[j-nums[i]];
        }
    }
    return dp[target];
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 8;
    vector<int>dp(n+1, 0);
    vector<int>nums = {2,3,5};
    cout<<combinationSum(n, nums); // 3
    
    return 0;
}