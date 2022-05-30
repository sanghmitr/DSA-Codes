#include<bits/stdc++.h>
using namespace std;

void findTopoSort(vector<vector<pair<int, int>>>&adj, int node, vector<bool>&vis, vector<int>&topo){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(!vis[nbr.first]){
            findTopoSort(adj, nbr.first, vis, topo);
        }
    }
    topo.push_back(node);
}
void shortest_path(vector<vector<pair<int, int>>>&adj, int src){
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> topo;

    for (int i = 0; i < n; i++){
        if(!vis[i])
            findTopoSort(adj, i, vis, topo);
    }

    reverse(topo.begin(), topo.end());
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int node : topo){
        //If the node has been reached previously
        if(dist[node] != INT_MAX){
            for(auto nbr : adj[node]){
                if(dist[node] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[node] + nbr.second;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << "Distance from " << src << " to node " << i << " is - " << dist[i]<<endl;
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 6;
    vector<vector<pair<int, int>>> adj(n);
    // edges are stored in {u, v, wt}.. u->v with wt weight;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {2, 3, 6}, {4, 2, 2}, {4, 5, 4}, {5, 3, 1}};
    
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
    }

    int src = 0;
    shortest_path(adj, src);
    return 0;
}