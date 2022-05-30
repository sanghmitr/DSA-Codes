// Undirected, unweighted, single source shorted path using BFS

#include<bits/stdc++.h>
using namespace std;

//Adjacency List
vector<vector<int>> adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(int src, vector<bool>&visited)
{
    visited[src] = true;
    for(auto nbr : adj[src])
    {
        if(!visited[nbr])
            dfs(nbr, visited);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 9;
    adj.resize(n);

    //Add Edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(0, 2);
    addEdge(4, 3);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(6, 7);
    addEdge(5, 8);

    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited);
            components++;
        }
    }
    cout << "Number of components in a graph : " << components << endl;
    return 0;
}