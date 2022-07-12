// https://leetcode.com/problems/paint-house-iii/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

class Solution
{
public:
    int MAX = 1000001;
    int solve(vector<int> &houses, vector<vector<int>> &cost, int colors,
              int target, int i, int prevColor, vector<vector<vector<int>>> &dp)
    {

        int m = houses.size();

        if (i >= m or target < 0)
        {
            if (target == 0)
            {
                return 0;
            }
            return MAX;
        }

        if (dp[i][prevColor][target] != -1)
            return dp[i][prevColor][target];

        int ans = MAX;
        if (houses[i] == 0)
        { // Not painted
            for (int k = 1; k <= colors; k++)
            {
                ans = min(ans, cost[i][k - 1] + solve(houses, cost, colors, target - (k != prevColor), i + 1, k, dp));
            }
        }
        else
        { // Already painted
            ans = solve(houses, cost, colors, target - (houses[i] != prevColor), i + 1, houses[i], dp);
        }
        return dp[i][prevColor][target] = ans;
    }
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int ans = solve(houses, cost, n, target, 0, 0, dp);
        if (ans > 1000000)
            return -1;
        return ans;
    }
};