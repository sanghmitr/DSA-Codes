// https://leetcode.com/problems/next-greater-element-ii

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<int>s;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
		    s.push(nums[i]);
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.size()==0)
                ans.push_back(-1);
            else if(!s.empty() and s.top()>nums[i])
                ans.push_back(s.top());
            else if(!s.empty() and s.top()<=nums[i])
            {
                while(!s.empty() and s.top()<=nums[i])
                    s.pop();
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}