//https://leetcode.com/problems/unique-paths/

//Memoisation
int solve(int i, int j, int m, int n, vector<vector<int>>&dp){
    if(i >= m or j >= n)
        return 0;
    
    if(i == m-1 and j == n-1){
        return 1;
    }
    if(dp[i][j] != 0)
        return dp[i][j];
    
    int down = 0, right = 0;

    down = solve(i+1, j, m, n, dp);
    right = solve(i, j+1, m, n, dp);
    
    return dp[i][j] = down + right;
}

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n, 0));
    return solve(0, 0, m, n, dp);
}

// Tabulation
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        dp[0][i] = 1;
    }
    for(int i=0; i<m; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}


// Space optimisation
int uniquePaths(int m, int n) {
    vector<int>prev(n, 1);
    
    for(int i=1; i<m; i++){
        vector<int>cur(n, 0);
        cur[0] = 1;
        for(int j=1; j<n; j++){
            cur[j] += prev[j] + cur[j-1];
        }
        prev = cur;
    }
    return prev[n-1];
}


//Using combinatorics = nCr(m+n-2, m-1) = nCr(m+n-2, n-1)
int uniquePaths(int m, int n){
    int N = m + n - 2;
    int r = m - 1;
    int ans = 1;
    
    //10C3 = (10*9*8)/(3*2*1)
    for (int i = 1; i <= r; i++){
        ans *= (N - r + i) / i;
    }
    return ans;
}
#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
