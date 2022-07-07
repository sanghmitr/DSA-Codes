/*

Rod cutting problem
-----------------------

N = 8
length = 1  2  3  4  5  6  7  8
---------------------------------
price  = 1  5  8  9  10 17 17 20

max profit = 22

*/

#include<bits/stdc++.h>
using namespace std;


int rod_cutting_recursive(int length, vector<int>&prices)
{
    if(length == 0)
        return 0;
    
    int maxProfit = 0;
    for(int i=1;i<=length;i++)
    {
        if(i <= length)
        {
            maxProfit = max(maxProfit, rod_cutting_recursive(length - i, prices) + prices[i-1]);
        }
    }
    return maxProfit;
}

int rod_cutting_memoisation(int length, vector<int>&prices, vector<int>&dp)
{
    if(length == 0)
        return 0;
    
    if(dp[length] != -1)
        return dp[length];
    int maxProfit = 0;
    for(int i=1;i<=length;i++)
    {
        if(i <= length)
        {
            maxProfit = max(maxProfit, rod_cutting_memoisation(length - i, prices, dp) + prices[i-1]);
        }
    }
    dp[length] = maxProfit;
    return maxProfit;
}

int rod_cutting_DP(int length, vector<int>&prices)
{
    vector<int>dp(length+1, -1);
    dp[0] = 0;

    for(int curlen=1;curlen<=length;curlen++)
    {
        for(int j=0;j<curlen; j++)
        {
            int cut = j + 1;
            int current_ans = prices[j] + dp[curlen - cut];
            dp[curlen] = max(dp[curlen], current_ans);
        }
    }
    return dp[length];
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //vector<int>prices = {1,5,8,9,10,17,17,20};
    //int length = 8; // ans = 22

    int length = 8;
    vector<int>prices = {3,5,8,9,10,17,17,20}; 

    cout<<rod_cutting_recursive(length, prices)<<endl;

    vector<int>dp(length+1, -1);
    dp[0] = 0;
    cout<<rod_cutting_memoisation(length, prices, dp)<<endl;

    cout<<rod_cutting_DP(length, prices)<<endl;
    return 0;
}