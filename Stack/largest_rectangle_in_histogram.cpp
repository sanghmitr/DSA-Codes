//https://leetcode.com/problems/largest-rectangle-in-histogram/

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
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>left_smaller(n), right_smaller(n);
        
        //Pair stores the <height, index>
        stack<pair<int, int>>s;
        
        // Find left smaller element and store difference of indices into the array
        for(int i=0; i<n; i++)
        {
            int ans = 0;
            while(!s.empty() and s.top().first >= heights[i])
                s.pop();
            
            if(s.empty())
                ans = (i == 0)? 1 : i+1;
            else
                ans = i - s.top().second;
            
            s.push({heights[i], i});
            left_smaller[i] = ans;
            //cout<<ans<<" ";
        }
        //cout<<endl;
        //Clear the stack for reuse
        while(!s.empty()) s.pop();
        // Find right smaller element and store difference of indices into the array
        for(int i=n-1; i>=0; i--)
        {
            int ans = 0;
            while(!s.empty() and s.top().first >= heights[i])
                s.pop();
            
            if(s.empty())
                ans = (i == n-1)? 1 : n-i;
            else
                ans = s.top().second - i;
            
            s.push({heights[i], i});
            right_smaller[i] = ans;
        }
        //for(auto x : right_smaller) cout<<x<<" ";
        //cout<<endl;
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int w = (left_smaller[i] + right_smaller[i] - 1);
            //if(w <= 0) w = 1;
            int h = heights[i];
            //cout<<w*h<<" ";
            ans = max(ans, w*h);
        }
        //cout<<endl<<endl;
        return ans;
    }
};