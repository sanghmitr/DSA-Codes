// https://leetcode.com/problems/next-greater-element-i

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n = nums2.size();
        int m = nums1.size();
        unordered_map<int, int>mp;
        for(int i=n-1; i>=0; i--)
        {
            if(s.empty())
            {
                mp[nums2[i]] = -1;
            }
            else if(s.top() > nums2[i])
            {
                mp[nums2[i]] = s.top();
            }
            else if(s.top() < nums2[i])
            {
                while(!s.empty() and s.top() < nums2[i])
                {
                    s.pop();
                }
                if(s.empty())
                    mp[nums2[i]] = -1;
                else
                    mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        
        for(int i=0; i<m; i++)
        {
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}