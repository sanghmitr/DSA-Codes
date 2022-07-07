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
    
    int n,sum;
    cin>>n>>sum;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    cout<<Count_SubsetSum(nums, sum, n)<<endl;
    return 0;
}

/*

5 11
2 3 7 8 10
Ans = 1

6 10
2 3 5 6 8 10
Ans = 3
*/