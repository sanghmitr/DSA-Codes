//https://binarysearch.com/problems/0-1-Knapsack

#include<bits/stdc++.h>
using namespace std;


int knapsack(vector<int>&weights, vector<int>&values, int capacity, int n)
{
    if(n == 0 or capacity == 0)
        return 0;

    if(weights[n-1] <= capacity)
    {
        return max(values[n-1] + knapsack(weights, values, capacity - weights[n-1], n-1), 
                    knapsack(weights, values, capacity, n-1));
    }
    else
        return knapsack(weights, values, capacity, n-1);
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