//https://leetcode.com/problems/combination-sum-ii

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&candidates, int target, int pos, vector<int>&path, vector<vector<int>>&ans){
    if(target < 0 or pos > candidates.size()) return;
    
    if(target == 0){
        sort(path.begin(), path.end());
        ans.push_back(path);
        return;
    }
    
    for(int i=pos; i<candidates.size(); i++){
        if(candidates[i] > target) return;
        
        if(i > pos and candidates[i] == candidates[i-1]) continue;
        
        path.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i+1, path, ans);
        path.pop_back();
    }
}
    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>path;
    
    sort(candidates.begin(), candidates.end());
    
    solve(candidates, target, 0, path, ans);
    
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}