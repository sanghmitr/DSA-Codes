#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
map<pair<long long, int>, long long> dp;
int k;
long long f(long long mask, int n)
{ // 2^K  * N
    if (dp.count({mask, n}))
        return dp[{mask, n}];
    else if (n == 0)
        return 0;
    long long &ans = dp[{mask, n}];
    long long msk = mask, bit, pw = 1, ck = 1;
    while (msk)
    { // O(K)
        bit = msk % 10;
        msk /= 10;
        if (bit > 0) // put nth element on ck position
            ans = max(ans, (a[n - 1] & ck) + f(mask - pw, n - 1));
        ck++;
        pw *= 10;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long mask = 2;
        for (int i = 2; i <= k; i++)
        {
            mask = mask * 10 + 2;
        }
        cout << f(mask, n) << '\n';
        dp.clear();
    }
    return 0;
}

/*
2
6
3
1 2 3 4 5 6
5
5
1 2 3 4 5

output = 
9
15


*/