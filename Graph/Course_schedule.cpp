//https://leetcode.com/problems/course-schedule

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
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>courses(numCourses);
        for(auto p : prereq)
        {
            int a = p[0] , b = p[1];
            courses[a].push_back(b);
        }
        
        int n = courses.size();
        vector<int> indeg(n + 1, 0);

        // populate indegree
        for (int u = 0; u < n; u++) {
            for (int v : courses[u]) {
                indeg[v]++;
            }
        }
        // push all nodes with zero indegree
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) q.push(i);
        }

        // edge case
        if (q.size() == 0) return false;

        // topo sort
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            order.push_back(u);
            q.pop();
            for (int v : courses[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        // if there's no cycle topo order will have n nodes in it
        return order.size() == n;
    }
};