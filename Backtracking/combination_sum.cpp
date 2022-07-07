//https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

void combinations(vector<int>&candidates, int target, int pos, vector<int>&path, vector<vector<int>>&ans)
{
    if(target < 0)
        return;
    
    if(target == 0)
    {
        ans.push_back(path);
        return;   
    }
    for(int i=pos;i<candidates.size();i++)
    {
        if(target >= candidates[i])
        {
            path.push_back(candidates[i]);
            combinations(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
    return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>path;
    //sort(candidates.begin(), candidates.end());
    
    combinations(candidates, target, 0, path, ans);
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}