// A graph that can be colored using exactly two colors is called bipartite graph
// A graph is called bipartite if does not have any odd length cycle

// https://leetcode.com/problems/possible-bipartition/

#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(vector<vector<int>>&adj, vector<int>&color, int node){
    if(color[node] == -1) color[node] = 1;
    
    for(auto nbr : adj[node]){
        if(color[nbr] == -1){
            color[nbr] = (color[node] == 1) ? 0 : 1;
            if(!dfsCheck(adj, color, nbr))
                return false;
        }
        else if(color[nbr] == color[node])
            return false;
    }
    return true;
}
    
bool checkBipartite(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>>adj(n);
    for(auto v : dislikes){
        adj[v[0]-1].push_back(v[1]-1);
        adj[v[1]-1].push_back(v[0]-1);
    }
    
    vector<int>color(n, -1);
    for(int i=0; i<n; i++)
    {
        if(color[i] == -1){
            if(!dfsCheck(adj, color, i)){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}