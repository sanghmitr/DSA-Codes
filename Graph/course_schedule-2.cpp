//https://leetcode.com/problems/course-schedule-ii

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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(numCourses);
        
        for(auto p : prereq){
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int>indeg(numCourses, 0);
        queue<int>q;
        //Genereate indegree vector
        for(int i=0; i<numCourses; i++){
            for(auto x : adj[i]){
                indeg[x]++;
            }
        }
        
        //Find all nodes with zero indegree and push them into the queue
        for(int i=0; i<numCourses; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        
        if(q.size() == 0) return {};
        
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr : adj[node]){
                indeg[nbr]--;
                if(indeg[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        if(ans.size() != numCourses) return {};
        return ans;
    }
};