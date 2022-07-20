// https://www.codingninjas.com/codestudio/library/longest-bitonic-subsequence

#include<bits/stdc++.h>
using namespace std;

vector<int> lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return dp;
}

int LongestBitonicSequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp1 = lengthOfLIS(nums);
    reverse(nums.begin(), nums.end());

    vector<int> dp2 = lengthOfLIS(nums);
    reverse(dp2.begin(), dp2.end());
    // reverse(nums.begin(), nums.end());

    int mx_bitonic_seq = 0;
    for (int i = 0; i < n; i++)
    {
        // cout<<nums[i]<<" "<<dp1[i]<<" "<<dp2[i]<<endl;
        mx_bitonic_seq = max(dp1[i] + dp2[i] - 1, mx_bitonic_seq);
    }
    return mx_bitonic_seq;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}