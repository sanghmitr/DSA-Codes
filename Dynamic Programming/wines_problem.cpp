//Prateek narang 2D dp

#include<bits/stdc++.h>
using namespace std;

//Top-down DP (Memoisation)
int wines(vector<vector<int>>&dp, vector<int>&prices, int L, int R, int y)
{
    if(L > R)
        return 0;

    if(dp[L][R] != -1)
        return dp[L][R];

    // Recursive case
    int pick_left = y * prices[L] + wines(dp, prices, L + 1, R, y + 1);
    int pick_right = y * prices[R] + wines(dp, prices, L, R - 1, y + 1);
    return dp[L][R] = max(pick_left, pick_right);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> prices = {2, 3, 5, 1, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << wines(dp, prices, 0, n - 1, 1) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}