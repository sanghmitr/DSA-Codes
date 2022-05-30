/* Topological sort is the ordering of the nodes such that if there is a 'directed' edge from
u -> v then u should come before v in the final order.

Topological sort can be applied only to Directed Acyclic graphs (DAGS).

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj ,vector<bool>&vis, int node, vector<int>&topo)
{
    vis[node] = true;
    for(int nbr : adj[node]){
        if(!vis[nbr]){
            dfs(adj, vis, nbr, topo);
        }
    }
    topo.push_back(node);
}
vector<int> topological_sort(vector<vector<int>>&adj){
    vector<int> topo;
    int n = adj.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < adj.size(); i++)
    {
        if(!vis[i]){
            dfs(adj, vis, i, topo);
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 6;
    vector<vector<int>> edges = {{5, 0}, {5, 2}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    vector<vector<int>> adj(n);

    for (auto e : edges){
        adj[e[0]].push_back(e[1]);
    }

    vector<int> topo = topological_sort(adj);
    for(auto v : topo)
        cout << v << " ";
    cout << endl;
    return 0;
}