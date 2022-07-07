#include<bits/stdc++.h>
using namespace std;

// O(N) time, constant space
int fib_constantSpace(int n)
{
    if(n == 0 or n == 1)
        return 1;
    int a = 1;
    int b = 1;
    int c = 0;
    for(int i=2;i<=n;i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

// O(N) time, O(N) space, BOTTOM-UP DP, Tabulation
int fib_bottomUP(int n)
{
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// O(N) time , O(N) space, TOP-DOWN DP
int fib_memoisation(int n, int dp[])
{
    if(n == 0 or n == 1)
        return 1;
    
    if(dp[n] != 0)
        return dp[n];
    return fib_memoisation(n-1, dp) + fib_memoisation(n-2, dp);
}

// O(2^N)
int fib_recursive(int n)
{
    if(n == 0 or n == 1)
        return 1;
    
    return fib_recursive(n-1) + fib_recursive(n-2);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // #ifndef ONLINE_JUDGE
    //     //for getting input from input.txt
    //     freopen("input.txt", "r", stdin);
    //     //for getting input from input.txt
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin>>n;

    int dp[n+1] = {0};
    cout<<fib_recursive(n)<<endl;
    cout<<fib_memoisation(n, dp)<<endl;
    cout<<fib_bottomUP(n)<<endl;
    cout<<fib_constantSpace(n)<<endl;
    return 0;
}