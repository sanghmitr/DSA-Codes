//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i=1; i<n; i++)
        {
            if(prices[i] - prices[i-1] > 0)
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};