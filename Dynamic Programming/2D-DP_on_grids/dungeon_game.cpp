// https://leetcode.com/problems/dungeon-game

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 and j == m - 1)
    {
        return (grid[i][j] <= 0) ? abs(grid[i][j]) + 1 : 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = 1e9, right = 1e9;
    if (i + 1 < n)
    {
        down = solve(grid, i + 1, j, n, m, dp);
    }

    if (j + 1 < m)
    {
        right = solve(grid, i, j + 1, n, m, dp);
    }

    int health = min(down, right) - grid[i][j];

    return dp[i][j] = (health <= 0) ? 1 : health;
}
int calculateMinimumHP(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(grid, 0, 0, n, m, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}