//https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

void permute(vector<int>&nums, vector<int>&op, vector<bool>&visited, vector<vector<int>>&ans)
{
    if(op.size() == nums.size())
    {
        ans.push_back(op);
        return;
    }
    
    for(int i=0;i<nums.size();i++)
    {
        if(!visited[i])
        {
            op.push_back(nums[i]);
            visited[i] = true;
            permute(nums, op, visited, ans);
            visited[i] = false;
            op.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<bool>visited(n, false);
    vector<int>op; 
    vector<vector<int>>ans;
    
    permute(nums, op, visited, ans);
    //sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>nums = {1,3,2};
    vector<vector<int>>ans = permute(nums);
    for(auto v : ans)
    {
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;
    }    
    return 0;
}
