//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include<bits/stdc++.h>
using namespace std;

//Memoisation
int solve(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(target == 0) return 1;
    if(i == 0) return arr[i] == target;

    if(dp[i][target] != -1) return dp[i][target];
    
    int notTake = solve(i - 1, target, arr, dp);
    int take = 0;
    if(arr[i] <= target)
        take = solve(i - 1, target - arr[i], arr, dp);
    return dp[i][target] = take + notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}


//tabulation
bool subsetSumToK(int n, int k, vector<int>&arr){
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++){
        for (int target = 1; target <= k; target++){
            bool notTake = dp[i - 1][target];
            bool take = false;

            if(arr[i] <= target){
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = take or notTake;
        }
    }
    return dp[n - 1][k];
}

//Space optimised
bool subsetSumToK(int n, int k, vector<int>&arr){

    vector<bool> prev(k + 1, false);
    vector<bool> cur(k + 1, false);
        
    prev[0] = true;
    cur[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++){
        for (int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;

            if(arr[i] <= target){
                take = prev[target - arr[i]];
            }
            cur[target] = take or notTake;
        }
        prev = cur;
    }
    return prev[k];
}



int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}