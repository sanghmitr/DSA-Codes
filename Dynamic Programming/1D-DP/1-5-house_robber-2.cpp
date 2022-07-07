// https://leetcode.com/problems/house-robber-ii/

#include<bits/stdc++.h>
using namespace std;

int robbing(vector<int> &nums)
{

    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {

        int robbed = nums[i];
        if (i > 1)
        {
            robbed = prev2 + nums[i];
        }
        int skipped = prev;
        int cur = max(robbed, skipped);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> nums1(nums.begin(), nums.begin() + n - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    int ans = max(robbing(nums1), robbing(nums2));
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}