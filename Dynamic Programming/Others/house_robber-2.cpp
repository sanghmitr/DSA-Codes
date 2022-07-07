//https://leetcode.com/problems/house-robber-ii/


#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int>dp(n, 0);
        if(n == 1)
            return max(nums[0], 0);
        else if(n == 2)
            return max({0, nums[0], nums[1]});
        
        int sum2 = max(nums[0], 0);
        int sum1 = max({0, nums[0], nums[1]});
        
        // If 1st element included then exclude last element, i.e. run loop till second last element;
        for(int i=2;i<n-1;i++)
        {
            int inc = nums[i] + sum2;
            int exc = sum1;
            sum2 = sum1;
            sum1 = max(inc, exc);
        }
        int candidate1 = max(sum1, sum2);
        
        // Exclude 1st element and include last element;
        sum2 = 0;
        sum1 = max({0, nums[1]}); 
        for(int i=2;i<n;i++)
        {
            int inc = nums[i] + sum2;
            int exc = sum1;
            sum2 = sum1;
            sum1 = max(inc, exc);
        }
        int candidate2 = max(sum1, sum2);
        return max(candidate1, candidate2);
    }
};