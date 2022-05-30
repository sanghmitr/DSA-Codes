//Kosaraju algorithm
// Strongly connected Components = A component in which from every node we can reach to every other node.

/*
Algorithm- 

1. sort all nodes in the order of finishing time. (apply topological sort)
2. Transpose the graph. (Reverse edge directions)
3. Apply DFS on transposed graph according to topological order.

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj, int node, vector<bool>&vis){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(adj, nbr, vis);
        }
    }
}

void dfsTopo(vector<vector<int>>&adj, int node, vector<bool>&vis, vector<int>&topo){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfsTopo(adj, nbr, vis, topo);
        }
    }
    topo.push_back(node);
}
vector<int> findTopo(vector<vector<int>>&adj){
    int n = adj.size();

    vector<bool> vis(n, false);
    vector<int> topo;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfsTopo(adj, i, vis, topo);
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;
}

int kosaraju_SCC(vector<vector<int>>&adj){
    int n = adj.size();
    //Step-1 => Find topo order
    vector<int> topo = findTopo(adj);

    // Step-2 => Transpose the graph (reverse edge direction)
    vector<vector<int>> transposed(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<adj[i].size(); j++){
            int nbr = adj[i][j];
            int node = i;
            transposed[nbr].push_back(i);
        }
    }

    //Step-3 => apply DFS according to topological order
    vector<bool> vis(n, false);
    int components = 0;
    for (auto node : topo){
        if(!vis[node]){
            components++;
            dfs(transposed, node, vis);
        }
    }
    return components;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    vector<vector<int>> adj(n);
    vector<vector<int>> edges = {
        {0, 1}, {1, 3}, {3, 4}, {1, 2}, {2, 0}};

    //create directed graph
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
    }

    int components = kosaraju_SCC(adj);
    cout << "Total strongly connected components are : " << components<<endl;
    return 0;
}