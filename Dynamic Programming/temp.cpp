#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>nums ={3,2,4,5};
    int ans = INT_MAX;
    int total = 0, cursum = 0;
    int n = nums.size();
    for(auto x : nums) total += x;

    cout<<total<<endl;
    int idx = 0;
    for(int i=0;i<n-1;i++)
    {
        cursum += nums[i];
        total -= nums[i];

        int x = cursum/(i+1);
        int y = total/(n-i-1);

        cout<<x<<" "<<y<<endl;
        if(ans > abs(y-x))
        {
            idx = i+1;
            ans = abs(y-x);
        }
    }

    cout<<idx;
    return 0;
}