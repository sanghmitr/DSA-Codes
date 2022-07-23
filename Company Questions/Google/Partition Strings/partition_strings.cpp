// https://leetcode.com/discuss/interview-question/2257966/Google-OA

#include<bits/stdc++.h>
using namespace std;
     

int partition(vector<int> &v, int m, int k, int n, vector<vector<int>> &dp) // function forming grp from backward so thats why condition is fliped.
{
    if (k == 0 and n == 0)
        return 1;
    if (k <= 0 or n <= 0)
        return 0;

    if (v[n - 1] % 2 == 0)
        return 0; // if starting val is even , invalid unable to form further grps

    if (dp[n][k] != -1)
        return dp[n][k];

    int maxx = 0;
    for (int i = m; i <= n; i++)
    {
        if (v[n - i] % 2 == 0) // if ending val is even , valid group
            maxx += partition(v, m, k - 1, n - i, dp);
        else
            continue;
    }
    return dp[n][k] = maxx;
}
int main()
{
    int N = 9;
    vector<int> v = {2, 3, 2, 3, 8, 7, 4, 2, 1};
    int m = 2, k = 3;                                             // minimum length of m
    vector<vector<int>> dp(v.size() + 1, vector<int>(k + 1, -1)); // dp array
    cout << partition(v, m, k, N, dp);
    return 0;
}