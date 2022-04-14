//https://leetcode.com/problems/subsets-ii/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

class Solution {
public:
    void subsetHelper(vector<int>&nums, int pos, vector<int>&op, vector<vector<int>>&ans)
    {

        ans.push_back(op);

        for(int i = pos; i<nums.size(); i++)
        {
            if(i == pos or nums[i] != nums[i-1])
            {
                op.push_back(nums[i]);
                subsetHelper(nums, i+1, op, ans);
                op.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int>op;
        vector<vector<int>>ans;
        subsetHelper(nums, 0, op, ans);

        return ans;
    }
};