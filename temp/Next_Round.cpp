//https://codeforces.com/contest/158/problem/A

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    int cnt = 0;
    int kth_score = 0;
    bool pos = true;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        if(nums[i] > 0 and i < k-1)
            cnt++;
        if(i == k-1)
        {
            kth_score = nums[i];
            if(nums[i] <= 0)
                pos = false;
            else
                cnt++;
        }
        if(i > k-1 and pos and nums[i] == kth_score)
            cnt++;
    }
    cout<<cnt;
    return 0;
}