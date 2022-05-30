#include<bits/stdc++.h>
using namespace std;

//Adjacency List
vector<vector<int>> adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs_helper(int src, vector<bool>&visited)
{
    cout << src << " -> ";
    visited[src] = true;
    for(auto nbr : adj[src])
    {
        if(!visited[nbr])
            dfs_helper(nbr, visited);
    }
}

void dfs()
{
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++)
    {
        if(!visited[i])
            dfs_helper(i, visited);
    }
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    adj.resize(n);

    //Add Edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(0, 2);
    addEdge(4, 3);
    addEdge(1, 3);
    addEdge(1, 4);

    dfs();
    return 0;
}