//https://binarysearch.com/problems/0-1-Knapsack

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(251, vector<int>(251, -1));

int knapsack(vector<int>&weights, vector<int>&values, int capacity, int n)
{
    if(n == 0 or capacity == 0)
        return 0;
    
    if(dp[n][capacity] != -1)
        return dp[n][capacity];

    if(weights[n-1] <= capacity)
    {
        dp[n][capacity] = max(values[n-1] + knapsack(weights, values, capacity - weights[n-1], n-1), 
                    knapsack(weights, values, capacity, n-1));
    }
    else
        dp[n][capacity] = knapsack(weights, values, capacity, n-1);
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

//Input
/* 3 5
1 2 3
1 5 3
*/