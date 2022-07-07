// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;

int quickselect(vector<int> &nums, int lo, int hi, int k)
{
    int pivot = nums[hi];
    int pi = partition(nums, pivot, lo, hi);

    if (k > pi)
    {
        return quickselect(nums, pi + 1, hi, k);
    }
    else if (k < pi)
    {
        return quickselect(nums, lo, pi - 1, k);
    }
    else
    {
        return nums[pi];
    }
}

int partition(vector<int> &nums, int pivot, int lo, int hi)
{
    int i = lo, j = lo;
    while (i <= hi)
    {
        if (nums[i] <= pivot)
        {
            swap(nums[i], nums[j]);
            i++, j++;
        }
        else
        {
            i++;
        }
    }
    return j - 1;
}

int minMoves2(vector<int> &nums)
{
    int n = nums.size();
    int k = n / 2;

    int median = quickselect(nums, 0, n - 1, k);
    // cout<<median<<endl;

    int ans = 0;
    for (auto x : nums)
        ans += abs(x - median);
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}