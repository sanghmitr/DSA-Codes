#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int solve(vector<int>&nums, int n)
{
    int mx = INT_MIN;
    for(auto x : nums)
        mx = max(x, mx);

    int total_gcd = nums[0];
    for (int i = 1; i<n; i++)
    {
        total_gcd = gcd(nums[i], total_gcd);
    }
    return mx/total_gcd;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<solve(nums, n);
    return 0;
}