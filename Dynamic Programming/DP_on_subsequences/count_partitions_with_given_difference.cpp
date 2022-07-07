// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

#include<bits/stdc++.h>
using namespace std;
int mod = (int)1e9 + 7;
int findways(vector<int> &nums, int i, int target, vector<vector<int>> &dp)
{
    // Since in constraints there nums[i] can be 0, so we need to handle edge cases
    if (i == 0)
    {
        if (nums[i] == 0 and target == 0)
            return 2; // here we have two choices-> either pick that 0 or skip it;
        if (target == 0 or nums[i] == target)
            return 1; // have to select that element;
        else
            return 0;
    }

    // if(i < 0 or target < 0) return 0;

    if (dp[i][target] != -1)
        return dp[i][target];

    int pick = 0, skip = 0;
    skip = findways(nums, i - 1, target, dp);
    if (nums[i] <= target)
    {
        pick = findways(nums, i - 1, target - nums[i], dp);
    }
    return dp[i][target] = (pick + skip) % mod;
}
int countPartitions(int n, int d, vector<int> &nums)
{
    int total = 0;
    for (auto &x : nums)
        total += x;

    /*
        total = S1 + S2
        difference = S1 - S2
        total + Difference = 2*S1
        (total + Difference)/2 = S1;
    */
   
    // We can not partition
    if ((total - d) < 0 or (total - d) % 2 == 1)
        return 0;

    int target = (total - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return findways(nums, n - 1, target, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    return 0;
}