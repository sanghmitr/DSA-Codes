// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mx = INT_MIN;
    int ans = 0;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        mx = max(mx, prices[i]);
        ans = max(ans, mx - prices[i]);
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