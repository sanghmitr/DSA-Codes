//https://leetcode.com/problems/minimum-size-subarray-sum/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(binary_search(nums.begin(), nums.end(), target))
            return 1;
        
        int ans = INT_MAX;
        int i = 0, j = 0;
        int cursum = 0;
        while(j < n)
        {
            cursum += nums[j];
            while(cursum >= target and i <= j)
            {
                ans = min(ans, j - i + 1);
                cursum -= nums[i++];
            }
            //cout<<nums[i]<<" "<<nums[j]<<" "<<cursum<<" "<<ans<<endl;
            j++;
        }
        if(ans == INT_MAX)
           return 0;
        return ans;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>nums = {2,3,1,2,4,3};
    Solution s;
    cout<<s.minSubArrayLen(7, nums);
    return 0;
}
