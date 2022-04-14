//https://leetcode.com/problems/subsets

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
    void subsetHelper(vector<int>&nums, int i, vector<int>&op, vector<vector<int>>&ans)
    {
        if(i == nums.size())
        {
            ans.push_back(op);
            return;
        }
        
        vector<int>op2 = op;
        op2.push_back(nums[i]);
        subsetHelper(nums, i+1, op2, ans);
        subsetHelper(nums, i+1, op, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        vector<vector<int>>ans;
        subsetHelper(nums, 0, op, ans);
        return ans;
    }
};