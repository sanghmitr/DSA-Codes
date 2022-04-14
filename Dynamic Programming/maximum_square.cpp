//https://leetcode.com/problems/maximal-square/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
//Tabulation DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};

// Memoisation
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<char>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        if(i >= n or j >= m or mat[i][j] =='0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1 + min({ solve(i+1, j, mat), solve(i+1, j+1, mat), solve(i, j+1, mat)});
        return dp[i][j] = ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        dp.resize(n, vector<int>(m, -1));
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == '1')
                {
                    int cur = solve(i, j, matrix);
                    sum = max(sum, cur);
                }
            }
        }
        return sum*sum;
    }
};