// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include<bits/stdc++.h>
using namespace std;

//Memoisation
int solve(vector<vector<int>>&nums, int day, int prev_task, vector<vector<int>>&dp){
    if(day == 0){
        int mx = INT_MIN;
        for(int i=0; i<3; i++){
            if(i != prev_task)
            mx = max(nums[0][i], mx);
        }
        return mx;
    }
    
    if(dp[day][prev_task] != -1) return dp[day][prev_task];
    
    int mx = 0;
    for(int task=0; task<3; task++){
        if(task != prev_task){
            int point = nums[day][task] + solve(nums, day-1, task, dp);
            mx = max(point, mx);
        }
    }
    return dp[day][prev_task] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return solve(points, n-1, 3, dp);
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n, vector<int>(4, 0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
    
    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last] = 0;
            int mx = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}


//Space optimised
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4, 0);
    
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});
    
    for(int day=1; day<n; day++){
        vector<int>temp(4, 0);
        for(int last=0; last<4; last++){
            temp[last] = 0;
            int mx = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}