#include<bits/stdc++.h>
using namespace std;

//O(N*TotalSum) space
//O(N*TotalSum) time
int minSubsetSum_Difference(vector<int>&nums, int n, int total_sum)
{
    vector<vector<bool>>dp(n+1, vector<bool>(total_sum+1));

    //Initializations
    for(int i=1;i<=total_sum;i++)
        dp[0][i] = false;
    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    //Fill DP matrix
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=total_sum; j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // Find minimum difference of subsets sums
    int min_diff = INT_MAX;
    //Check the last row of DP matrix
    for(int j=total_sum/2;j>=0;j--)
    {
        if(dp[n][j])
        {
            min_diff = min((total_sum-j)-j, min_diff);
        }
    }
    return min_diff;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int>nums(n);
    int total_sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        total_sum += nums[i];
    }

    cout<<minSubsetSum_Difference(nums, n, total_sum);
    return 0;
}

/* Testcase-1
6
1 3 4 2 2 1
Ans = 1

4
1 6 11 5
Ans = 1

*/