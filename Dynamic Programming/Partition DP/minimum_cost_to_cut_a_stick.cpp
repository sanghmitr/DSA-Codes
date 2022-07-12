//

#include<bits/stdc++.h>
using namespace std;

//Tabulation
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int mn = INT_MAX;
            for (int k = i; k <= j; k++)
            {

                int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                mn = min(cost, mn);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][c];
}

//Memoisation
int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + solve(cuts, i, k - 1, dp) + solve(cuts, k + 1, j, dp);
        mn = min(cost, mn);
    }
    return dp[i][j] = mn;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solve(cuts, 1, c, dp);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}