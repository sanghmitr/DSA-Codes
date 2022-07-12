// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxlen = 1, ans = 0;
    vector<int> cnt(n, 1), dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                // this condition is checking that the same length of LIS again found so add it to count array.
                else if (dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    // find the longest increasing subsequence of the whole sequence
    // sum valid counts
    for (int i = 0; i < n; i++)
        if (dp[i] == maxlen)
            ans += cnt[i];
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}