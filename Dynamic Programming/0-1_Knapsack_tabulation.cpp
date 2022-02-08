#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&weights, vector<int>&values, int capacity, int n)
{
    vector<vector<int>>dp(n+1, vector<int>(capacity, 0));

   for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            if(weights[i-1] <= j)
            {
                dp[i][j] = max((values[i-1] + dp[i-1][j - weights[i-1]]), dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int n,capacity;
    cin>>n>>capacity;
    vector<int>weights(n),values(n);
    for(int i=0;i<n;i++)
        cin>>weights[i];
    for(int i=0;i<n;i++)
        cin>>values[i];

    cout<<knapsack(weights, values, capacity, n);
    return 0;
}