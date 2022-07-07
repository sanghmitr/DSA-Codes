//https://leetcode.com/problems/cherry-pickup-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m){
            return -1e8;
        }
        
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        
        if(i == n-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        int mx = -1e8;
        //Explore all paths of both robots simultaneously
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2){
                    value = grid[i][j1];
                }
                else{
                    value = grid[i][j1] + grid[i][j2]; 
                }
                value += solve(i+1, j1+dj1, j2+dj2, grid, dp);
                mx = max(mx, value);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m-1, grid, dp);
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}