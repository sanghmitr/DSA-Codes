//https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int>prev(m);
    prev[0] = grid[0][0];
    for(int i=1; i<m; i++){
        prev[i] = grid[0][i] + prev[i-1];
    }
    
    for(int i=1; i<n; i++){
        vector<int>cur(m);
        cur[0] = prev[0] + grid[i][0];
        for(int j=1; j<m; j++){
            cur[j] = grid[i][j] + min(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m-1];
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}