//https://leetcode.com/problems/task-scheduler

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
    
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        
        priority_queue<int>pq;
        
        map<char, int>mp;
        for(auto task : tasks)
            mp[task]++;
        
        
        for(auto p : mp)
        {
            pq.push(p.second);
        }
        
        int time = 0;
        queue<pair<int, int>>q;
        
        while(!pq.empty() or !q.empty())
        {
            time++;
            if(!pq.empty())
            {
                int taskCount = pq.top();
                pq.pop();
                
                taskCount--;
                if(taskCount > 0)
                {
                    q.push({taskCount, time+n});
                }
            }
            if(!q.empty() and q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};