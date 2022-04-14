//https://leetcode.com/problems/permutations-ii/

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
    set<vector<int>>s;
    
    void permute(vector<int>&nums, vector<int>&op, vector<bool>&visited)
    {
        if(op.size() == nums.size())
        {
            s.insert(op);
            return;
        }
        
        for(int i=0;i<nums.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                op.push_back(nums[i]);
                permute(nums, op, visited);
                op.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        s.clear();
        vector<int>op;
        vector<bool>visited(nums.size(), false);
        
        permute(nums, op, visited);
        vector<vector<int>>ans;
        for(auto v : s)
            ans.push_back(v);
        return ans;
    }
};