#include<bits/stdc++.h>
using namespace std;

int frogJump_Tabulation(int n, vector<int> &heights, int k)
{
    vector<int>dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i<n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j >= 0){
                int jumps = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << frogJump_Tabulation(n, heights, k) << endl;
    
    return 0;
}