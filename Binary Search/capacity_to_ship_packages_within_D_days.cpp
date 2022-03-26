//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days


// O(NlogN) solution.... Optimization using binary search
//Similar questions - split array largest sum  https://leetcode.com/problems/split-array-largest-sum/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& weights, int capacity, int days)
    {
        int d = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
            if(sum > capacity)
            {
                d++;
                sum = weights[i];
            }
        }
        return d <= days; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mx = 0;
        int sum = 0;
        int n  = weights.size();
        for(auto x : weights)
        {
            mx = max(mx, x);
            sum += x;
        }
        
        //If number of wts are equal to number of days available then in one day we can ship only one weight...so answer will be the maximum sized weight.
        if(n == days)
            return mx;
        
        //Otherwise, apply binary search
        // Range for binary search will be (maximum weight that can be send in one day, all the weights to be sent in one day)
        int lo = mx;
        int hi = sum;
        int ans = 0;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            //isPossible function checks that the given maximum capacity is possible to sent within given days or not
            if(isPossible(weights, mid, days))
            {
                //if possible then try to reduce the search space and find more optimal answer.
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
}; 
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solution s;
    vector<int>weights = {3,2,2,4,1,4};
    int days = 3; //ans = 6
    cout<<s.shipWithinDays(weights, days);
    return 0;
}
