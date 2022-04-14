//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
// Similar to count number of islands
class Solution {
public:
    void dfs(vector<vector<int>>& stones, int idx, vector<bool>& visited)
    {
        visited[idx] = true;
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            if(!visited[i] and (stones[idx][0] == stones[i][0] or stones[idx][1] == stones[i][1]))
            {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visited(n, false);
        
        int disjoint_sets = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(stones, i, visited);
                disjoint_sets++;
            }
        }
        
        return stones.size() - disjoint_sets;
    }
};
