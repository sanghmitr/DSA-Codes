//

#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>>&costs){
    int n = costs.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    int last = -1, lastidx = -1;

    int ans = INT_MAX;
    for (int i = 0; i < costs[0].size(); i++)
    {
        dp[0][i] = costs[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];

        if (i == n - 1)
        {
            ans = min({dp[i][0], dp[i][1], dp[i][2]});
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