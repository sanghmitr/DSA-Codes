#include<bits/stdc++.h>
using namespace std;


// O(nlogn) solution using Binary search
int lengthOfLIS(vector<int>& arr) 
{
    int n = arr.size();
    vector<int>lis;
    lis.push_back(arr[0]);
    
    for(int i=1; i<n; i++)
    {
        if(lis.back() < arr[i])
            lis.push_back(arr[i]);
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    return lis.size();
}

// O(n^2) solution using DP    
int lis(vector<int>& arr)
{
    int n = arr.size();

    vector<int>dp(n, 1);
    int len = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>arr = {50,4,10,8,30,100};
    cout<<lis(arr)<<endl;
    return 0;
}