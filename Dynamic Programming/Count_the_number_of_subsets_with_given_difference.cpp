//https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp

#include<bits/stdc++.h>
using namespace std;

// Time O(N*Sum)
// Space O(N*Sum)
int Count_SubsetSum(vector<int>&nums, int sum, int n)
{
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    //Initializations
    dp[0][0] = 1;
    for(int i=1;i<=sum;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++)
        dp[i][0] = 1;
    
    //DP logic
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,diff;
    cin>>n>>diff;
    vector<int>nums(n);
    int total_sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        total_sum += nums[i];
    }

    int reqSum = (diff + total_sum)/2;

    cout<<Count_SubsetSum(nums, reqSum, n)<<endl;
    return 0;
}

/* 
4 1
1 1 3 2

n = 4
diff = 1
arr = 1 1 3 2
ans = 3

subsets possible = {1,3} and {1,2}
                   {1,2} and {1,3}
                   {1,1,2} and {3}
*/