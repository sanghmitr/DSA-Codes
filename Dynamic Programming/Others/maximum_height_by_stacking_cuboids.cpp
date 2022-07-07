//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboid) {
        for (auto& a : cuboid)
            sort(begin(a), end(a));
        
        
        cuboid.push_back({0, 0, 0});
        
        sort(begin(cuboid), end(cuboid));
        
           
        int n = cuboid.size(), res = 0;
        vector<int> dp(n);
        
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (cuboid[i][0] <= cuboid[j][0] and 
                    cuboid[i][1] <= cuboid[j][1] and 
                    cuboid[i][2] <= cuboid[j][2]) 
                {
                    dp[j] = max(dp[j], dp[i] + cuboid[j][2]);
                    res = max(res, dp[j]);
                }
            }   
        }    
        return res;
    }
};
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}