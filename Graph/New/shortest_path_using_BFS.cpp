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

vector<int> bfs(int src)
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

    int n = 5;
    adj.resize(n);

    //Add Edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(0, 2);
    addEdge(4, 3);
    addEdge(1, 3);
    addEdge(1, 4);

    // Find all shortest distances starting from node 0;
    vector<int>distances, parent = bfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << "from 0 to node-" << i << " distance is : " << distances[i]<<endl;
    }
    return 0;
}