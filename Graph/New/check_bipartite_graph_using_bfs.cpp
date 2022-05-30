//https://leetcode.com/problems/is-graph-bipartite/
// Done using graph coloring

// A graph that can be colored using exactly two colors is called bipartite graph
// A graph is called bipartite if does not have any odd length cycle

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>colors(n, -1);
        // Here this for loop is necessary only if graph is disconnected 
        //i.e. check for all components of a graph
        for(int i=0; i<n; i++)
        {
            if(colors[i] != -1) continue;
            
            queue<int>q;
            q.push(i);
            colors[i] = 1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                int currentColor = colors[node];

                for(auto nbr : graph[node])
                {
                    if(colors[nbr] == -1)
                    {
                        q.push(nbr);
                        colors[nbr] = (currentColor == 1) ? 0 : 1;
                    }
                    else if(colors[nbr] == currentColor)
                        return false;
                    else
                        continue;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

