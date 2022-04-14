#include<bits/stdc++.h>
using namespace std;

int getMinCost(vector<int>stones)
{
    int n = stones.size();
    vector<int>dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(stones[1] - stones[0]);

    for(int i=2;i<n;i++)
    {
        int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];
        dp[i] = min(op1, op2);
    } 
    return dp[n-1];
}       
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int>stones(n);
    for(int i=0;i<n;i++)
        cin>>stones[i];

    cout<<getMinCost(stones)<<endl;
    return 0;
}
// input
/*

6
30 10 60 10 60 50

*/

// ans  = 40