//

#include<bits/stdc++.h>
using namespace std;

// Space optimisation with O(N *N) time
int printLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1), hash(n);

    int len = 1, lastidx = -1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] and 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if(len < dp[i]){
            len = dp[i];
            lastidx = i;
        }
    }

    vector<int> res(len);
    res[0] = nums[lastidx];
    int j = 1;
    while(hash[lastidx] != lastidx){
        lastidx = hash[lastidx];
        res[j++] = nums[lastidx];
    }

    //Print the LIS
    for(auto x : res)
        cout << x << " ";
        
    return len;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}