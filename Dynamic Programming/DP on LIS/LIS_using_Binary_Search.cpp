// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;
//O(nlogn)
int lengthOfLIS(vector<int>&nums){
    //Based on the intution to replace the elements by finding their correct position in the final LIS array.

    vector<int> lis;
    lis.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < nums.size(); i++){
        if(nums[i] > lis.back()){
            lis.push_back(nums[i]);
            len++;
        }
        else{
            int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[idx] = nums[i];
        }
    }
    return len;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}