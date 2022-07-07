#include<bits/stdc++.h>
using namespace std;

int minimumDifferenceSubsetSum(vector<int>&nums){
    int total = 0;
    int n = nums.size();
    for(auto x : nums) total += x;
    cout << "Total : " << total<<endl;

    vector<vector<bool>>dp(n, vector<bool>(total + 1, false));
    
    //Initialize the first column with zeros
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    //In the 1st row only one entry can be true
    if(nums[0] <= total) dp[0][nums[0]] = true;
    
    for(int i=1; i<n; i++){
        for(int target = 1; target <= total; target++){
            bool take = false;
            bool skip = dp[i-1][target];
            
            if(nums[i] <= target){
                take = dp[i-1][target - nums[i]];
            }
            dp[i][target] = take or skip;
        }
    }

    int ans = INT_MAX;
    //Traverse in the last row and find out the answer
    for(int i=0; i<=total; i++){
        if(dp[n-1][i] == true){
            ans = min(ans, abs(i - (total - i)));
        }
    }
    return ans;
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {2,3,5,7,17,10,12};
    cout << minimumDifferenceSubsetSum(nums);
    return 0;
}