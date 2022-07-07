// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &price, int len, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (len)*price[i];
    }
    if (dp[i][len] != -1)
        return dp[i][len];

    int take = INT_MIN;
    int notTake = solve(price, len, i - 1, dp);
    if (i + 1 <= len)
    {
        take = price[i] + solve(price, len - i - 1, i, dp);
    }
    return dp[i][len] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    int len = price.size();
    vector<vector<int>> dp(len, vector<int>(n + 1, -1));
    return solve(price, n, len - 1, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}