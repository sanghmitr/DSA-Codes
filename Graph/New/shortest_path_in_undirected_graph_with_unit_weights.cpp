#include<bits/stdc++.h>
using namespace std;

// Shortest path in an undirected graph having no weights/ unit weights with edges 
vector<int> bfs(vector<vector<int>>&adj, int src)
{
    int n = adj.size();
    vector<int> visited(n, false);
    vector<int> dist(n, 0);

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int nbr : adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
                dist[nbr] = dist[node] + 1;
            }
        }
    }
    return dist;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 9;
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 6}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};

    vector<vector<int>> adj(n);
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int source = 0;
    vector<int>distances = bfs(adj, source);
    for (int i = 0; i < n; i++)
    {
        cout << "from 0 to node-" << i << " distance is : " << distances[i]<<endl;
    }
    return 0;
}