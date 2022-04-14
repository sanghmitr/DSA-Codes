//https://leetcode.com/problems/top-k-frequent-elements/
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto x : nums) mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto p : mp)
        {
            if(pq.size() == k)
            {
                if(pq.top().first < p.second)
                {
                    pq.pop();
                }
                else
                    continue;
            }
            pq.push({p.second, p.first});
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};