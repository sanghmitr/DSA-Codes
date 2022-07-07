// DSA Udemy prateek narang

#include<bits/stdc++.h>
using namespace std;
/*
Approaches-
1. Recursive
2. Top down
3. Bottom-up
4. Bottom-up optimize recurrence
*/

//Recursive
int countWays(int n, int k)
{
    if(n == 0)
        return 1;
    
    if(n < 0)
        return 0;
    
    int ans = 0;
    for(int i=1;i<=k;i++)
    {   
        ans += countWays(n-i, k);
    }
    return ans;
}

//Top down
int countWaysTD(int n, int k, int *dp)
{
    if(n == 0)
        return 1;
    
    if(n < 0)
        return 0;
    
    if(dp[n] != 0)
        return dp[n];

    int ans = 0;
    for(int i=1;i<=k;i++)
    {   
        ans += countWays(n-i, k);
    }
    dp[n] = ans;
    return ans;
}

//Bottom Up O(n*k)
int countWaysBU(int n, int k)
{
    vector<int>dp(n+1,0);

    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int jump=1; jump<=k; jump++)
        {
            if(i-jump >= 0)
                dp[i] += dp[i - jump];
        }
    }
    return dp[n];
}

//Bottom up optimized O(n)
int countWaysBUO(int n, int k)
{
    vector<int>dp(n+1, 0);

    dp[0] = dp[1] = 1;

    for(int i=2;i<=k;i++)
    {
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1; i<=n; i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;
    cin>>n>>k;

    int dp[10000] = {0};
    cout<<"Recursive : "<<countWays(n,k)<<endl;
    cout<<"Top Down : "<<countWaysTD(n,k,dp)<<endl;
    cout<<"Bottom Up : "<<countWaysBU(n,k)<<endl;
    cout<<"Bottom Up optimized : "<<countWaysBUO(n,k)<<endl;
    return 0;
}