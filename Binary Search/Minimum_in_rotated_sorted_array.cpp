//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        while(s<e)
        {
            int mid = s +(e-s)/2;
            if(nums[e] < nums[mid])
            {
                s = mid + 1;    
            }
            else
                e = mid;
        }
        //cout<<nums[s]<<" "<<nums[e]<<endl;
        return nums[s];
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    vector<int>nums = {4,5,6,7,0,1,2,3};
    cout<<s.findMin(nums);
    return 0;
}