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
    
    int n,sum = 0;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        sum += nums[i];
    }

    //If total sum is odd then equal partition is not possible
    if(sum%2 == 1)
    {
        cout<<"Not Possible"<<endl;
        return 0;
    }

    //If there is sum/2 subset is possible then we can equally divide array into two subsets of same sum.
    if(isSubsetSum(nums, sum/2, n))
        cout<<"Possible"<<endl;
    else
        cout<<"Not Possible"<<endl;
    return 0;
}

/*

4
1 5 5 11
Ans = Possible

6
1 8 2 7 9 6
ans = Not Possible
*/