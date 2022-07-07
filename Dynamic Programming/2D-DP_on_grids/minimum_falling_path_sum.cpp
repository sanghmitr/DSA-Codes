//https://leetcode.com/problems/minimum-falling-path-sum

#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0){
                dp[i][j] = matrix[i][j];
            }
            else{
                int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
                if(j-1 >= 0){
                    op1 = dp[i-1][j-1];
                }
                if(j+1 < n){
                    op3 = dp[i-1][j+1];
                }
                
                op2 = dp[i-1][j];
                
                dp[i][j] = matrix[i][j] + min({op1, op2, op3});
            }
            
            if(i == n-1){
                ans = min(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}