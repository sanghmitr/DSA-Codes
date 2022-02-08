#include<bits/stdc++.h>
using namespace std;

// Time O(N*Sum)
// Space O(N*Sum)
bool isSubsetSum(vector<int>&nums, int sum, int n)
{
    vector<vector<bool>>dp(n+1, vector<bool>(sum+1));
    //Initializations
    dp[0][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;

    for(int i=1;i<=n;i++)
        dp[i][0] = true;
    
    //DP logic
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
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

    if(isSubsetSum(nums, sum, n))
        cout<<"Possible"<<endl;
    else
        cout<<"Not Possible"<<endl;
    return 0;
}

/*

5 11
2 3 7 8 10
Ans = Possible

4 4
1 8 2 5
ans = Not Possible
*/