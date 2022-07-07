#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

//Memoisation + 3D DP------------------------------------------------------------------------------------
class Solution {
public:
    
    int solve(int r1, int c1, int r2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        
        int c2 = r1 + c1 - r2;
        
        if(r1 >= n or r2 >= n or c1 >= m or c2 >= m or grid[r1][c1] == -1 or grid[r2][c2] == -1){
            return INT_MIN;
        }
        //If p1 and p2 reach destination
        if(r1 == n-1 and c1 == m-1) return grid[r1][c1];
        
        if(dp[r1][c1][r2] != 0){
            return dp[r1][c1][r2];
        }

        int cherries = 0;
        if(r1 == r2 and c1 == c2){
            cherries += grid[r1][c1];
        }
        else{
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = solve(r1, c1+1, r2, grid, dp);
        int f2 = solve(r1+1, c1, r2,  grid, dp);
        int f3 = solve(r1+1, c1, r2+1, grid, dp);
        int f4 = solve(r1, c1+1, r2+1, grid, dp);
        
        cherries += max({f1, f2, f3, f4});
        return dp[r1][c1][r2] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n)));
        
        int ans = solve(0 ,0, 0, grid, dp);
        if(ans < 0)
            return 0;
        return ans;
    }
};


//Memoisation + 4D Dp ------------------------------------------------------------------------------------------
class Solution {
public:
    
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>&grid, vector<vector<vector<vector<int>>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(r1 >= n or r2 >= n or c1 >= m or c2 >= m or grid[r1][c1] == -1 or grid[r2][c2] == -1){
            return INT_MIN;
        }
        //If p1 and p2 reach destination
        if(r1 == n-1 and c1 == m-1) return grid[r1][c1];
        
        if(dp[r1][c1][r2][c2] != 0){
            return dp[r1][c1][r2][c2];
        }

        int cherries = 0;
        if(r1 == r2 and c1 == c2){
            cherries += grid[r1][c1];
        }
        else{
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = solve(r1, c1+1, r2, c2+1, grid, dp);
        int f2 = solve(r1+1, c1, r2, c2+1, grid, dp);
        int f3 = solve(r1+1, c1, r2+1, c2, grid, dp);
        int f4 = solve(r1, c1+1, r2+1, c2, grid, dp);
        
        cherries += max({f1, f2, f3, f4});
        return dp[r1][c1][r2][c2] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<vector<vector<int>>>>dp(n, vector<vector<vector<int>>>(n,
                                                                    vector<vector<int>>(n, vector<int>(n))));
        
        int ans = solve(0 ,0, 0, 0, grid, dp);
        if(ans < 0)
            return 0;
        return ans;
    }
};


//backtracking ----------------------------------------------------------------------------------------------
class Solution {
public:
    int ans = 0;
    
    void bottom_to_top(int row, int col, vector<vector<int>>&grid, int total){
        if(row < 0 or col < 0 or grid[row][col] == -1){
            return;
        }
        
        if(row == 0 and col == 0){
            ans = max(ans, total);
            return;
        } 
        int cherries =  grid[row][col];
        grid[row][col] = 0;
        bottom_to_top(row, col-1, grid, total + cherries);
        bottom_to_top(row-1, col, grid, total + cherries);
        grid[row][col] = cherries;
    }
    
    void top_to_bottom(int row, int col, vector<vector<int>>&grid, int total){
        if(row >= grid.size() or col >= grid[0].size() or grid[row][col] == -1){
            return;
        }
        
        if(row == grid.size()-1 and col == grid[0].size()-1){
            bottom_to_top(row, col, grid, total);
        }
        
        int cherries =  grid[row][col];
        grid[row][col] = 0;
        top_to_bottom(row, col+1, grid, total + cherries);
        top_to_bottom(row+1, col, grid, total + cherries);
        grid[row][col] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        top_to_bottom(0 ,0, grid, 0);
        return ans;
    }
};