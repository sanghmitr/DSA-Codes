//https://leetcode.com/problems/subarrays-with-k-different-integers/

//Leetcode hard - important problem

class Solution {
public:
    
    //Number of subarrays with atmost K distinct 
    int subWithAtmostK(vector<int>&nums, int k){
        int start = 0, end = 0; int n = nums.size();
        
        int ans = 0;
        unordered_map<int, int>mp;
        while(end < n){
            mp[nums[end]]++;
            
            while(mp.size() > k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            ans += (end - start);
            end++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subWithAtmostK(nums, k) - subWithAtmostK(nums, k-1);
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}