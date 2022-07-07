// Count and print all subsequences whose sum is equal to K


#include<bits/stdc++.h>
using namespace std;


//Tabulation
int solve_tabulation(vector<int>&nums, int target){

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    //Initialize
    for (int i = 0; i<n; i++){
        dp[i][0] = 1;
    }

    if(nums[0] <= target)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 1; sum <= target; sum++)
        {
            int take = 0, notTake = 0;
            if (nums[i] <= sum)
            {
                take = dp[i - 1][sum - nums[i]];
            }
            notTake = dp[i - 1][sum];

            dp[i][sum] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

// Memoisation
int solve_memoised(vector<int>&nums, int i, int target, vector<vector<int>>&dp){
    if(target < 0 or i < 0)
        return 0;
    
    if(target == 0)
        return 1;

    if(dp[i][target] != -1)
        return dp[i][target];

    if(i == 0){
        return nums[i] == target;
    }

    int res = 0;
    res += solve_memoised(nums, i - 1, target - nums[i], dp);
    res += solve_memoised(nums, i - 1, target, dp);
    return dp[i][target] = res;
}

//Recursive solution for both counting and printing the subsequences
int solve(vector<int>&nums, int i, int sum, int target, vector<int>&path, vector<vector<int>>&ans){
    if(sum > target)
        return 0;
    
    if(i > nums.size())
        return 0;
    
    if(sum == target){
        ans.push_back(path);
        return 1;
    }

    int res = 0;
    path.push_back(nums[i]);
    res += solve(nums, i + 1, sum + nums[i], target, path, ans);
    path.pop_back();
    res += solve(nums, i + 1, sum, target, path, ans);
    return res;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {1, 2, 2, 3};
    int target = 3;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));


    //Recursive solution to count and print all subsequences
    vector<int> path;
    vector<vector<int>> ans;
    cout << solve(nums, 0, 0, target, path, ans) << endl;
    for(auto v: ans){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    //Memoisation 
    cout << "Memoised solution : " << solve_memoised(nums, n-1, target, dp)<<endl;
    cout << "Tabulation solution : " << solve_tabulation(nums, target)<<endl;

    return 0;
}