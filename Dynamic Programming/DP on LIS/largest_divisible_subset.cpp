// https://leetcode.com/problems/largest-divisible-subset

#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int len = 1, lastidx = 0;
    hash[0] = 0;

    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 and dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (len < dp[i])
        {
            len = dp[i];
            lastidx = i;
        }
    }

    vector<int> res(len);
    res[0] = nums[lastidx];
    int j = 1;
    while (hash[lastidx] != lastidx)
    {
        lastidx = hash[lastidx];
        res[j++] = nums[lastidx];
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}