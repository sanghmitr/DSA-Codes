#include<bits/stdc++.h>
using namespace std;

//Recursive
int lcs(string s1, string s2, int i, int j)
{
    if(i == s1.length() or j == s2.length())
        return 0;
    
    //recursive case
    if(s1[i] == s2[j])
    {
        return 1 + lcs(s1, s2, i + 1, j + 1);
    }

    int op1 = lcs(s1, s2, i + 1, j);
    int op2 = lcs(s1, s2, i, j + 1);
    return max(op1, op2);
}

//Top-down (Memoisation)
int lcsTopDown(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if(i == s1.length() or j == s2.length())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    //recursive case
    if(s1[i] == s2[j])
    {
        dp[i][j] =  1 + lcsTopDown(s1, s2, i + 1, j + 1, dp);
        return dp[i][j];
    }

    int op1 = lcsTopDown(s1, s2, i + 1, j, dp);
    int op2 = lcsTopDown(s1, s2, i, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}

// Bottom up

int lcsBottomUp(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}

//Space optimised
int longestCommonSubsequence(string text1, string text2) {
    if(text1 == text2)
        return text1.length();
    
    int n1 = text1.length();
    int n2 = text2.length();
    
    vector<int>prev(n2+1, 0), cur(n2+1, 0);
    
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(text1[i-1] == text2[j-1])
            {
                cur[j] = 1 + prev[j-1];
            }
            else
                cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[n2];
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1 = "ABCD";
    string s2 = "ABEDG";

    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout << lcs(s1, s2, 0, 0)<<endl;
    cout << lcsTopDown(s1, s2, 0, 0, dp)<<endl;
    cout << lcsBottomUp(s1, s2) << endl;
    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}