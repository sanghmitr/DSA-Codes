#include <bits/stdc++.h>
using namespace std;
#define read(x)       \
    for (auto &y : x) \
    cin >> y
#define write(x)      \
    for (auto &y : x) \
    cout << y <<

#define ll long long
#define SLAYER                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define pb push_back
#define mk make_pair
#define pii pair<long long, long long>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int32_t main()
{
    SLAYER;
    vector<vector<map<long long, long long>>> dp;
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        dp.resize(n, vector<map<ll, ll>>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        int c;
        cin >> c;
        dp[0][0][arr[0][0] % c] = 1;
        for (int i = 1; i < n; i++)
        {
            for (auto x : dp[i - 1][0])
            {
                dp[i][0][(x.first + arr[i][0]) % c] = 1;
            }
        }
        for (int j = 1; j < m; j++)
        {
            for (auto x : dp[0][j - 1])
            {
                dp[0][j][(arr[0][j] + x.first)] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                for (auto x : dp[i - 1][j])
                {
                    dp[i][j][(x.first + arr[i][j]) % c] += x.second;
                }
                for (auto x : dp[i][j - 1])
                {
                    dp[i][j][(x.first + arr[i][j]) % c] += x.second;
                }
                // cout << i << " " << j << endl;
                for (auto x : dp[i][j])
                {
                    // cout << x.first << " -> " << x.second << endl;
                }
                // cout << endl;
            }
        }
        cout << dp[n - 1][m - 1][0] << endl;
    }
    return 0;
}

/*
1
3
3
1 2 3
4 5 6
7 8 9
23
*/