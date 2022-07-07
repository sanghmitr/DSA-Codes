/*
Count the number of BST that can be formed using N nodes, numbered from 1 to N.

Input - 
3
4

Output
5 
14

*/

#include<bits/stdc++.h>
using namespace std;

// Recursive
int countBST(int n)
{
    if(n == 0 or n == 1)
        return 1;
    
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int x = countBST(i-1);
        int y = countBST(n-i);
        ans += x*y;
    }
    return ans;
}

//Top down - memoisation
int countBST_TopDown(int n, vector<int>&dp)
{
    if(n == 0 or n == 1)
        return 1;
    if(dp[n] != 0)
        return dp[n];
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int x = countBST(i-1);
        int y = countBST(n-i);
        ans += x*y;
    }
    return dp[n] = ans;
}

//Bottom-up
int countBST_BottomUp(int N)
{
    vector<int>dp(N+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int n=2; n<=N; n++)
    {
        for(int i=1; i<=n; i++)
        {
            dp[n] += dp[i-1]*dp[n-i];
        }
    }
    return dp[N];
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 5;
    cout<<countBST(n)<<endl;
    vector<int>dp(n+1, 0);
    cout<<countBST_TopDown(n, dp)<<endl;
    cout<<countBST_BottomUp(n)<<endl;
    return 0;
}