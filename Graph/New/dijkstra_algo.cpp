#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>&adj, int src){
    int n = adj.size();
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // pair<distance, node>

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;

        for(auto temp : adj[node]){
            int nbr = temp.first;
            int weight = temp.second;

            if(dist[nbr] > dist[node] + weight){
                dist[nbr] = dist[node] + weight;
                pq.push({dist[nbr], nbr});
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
    vector<vector<pair<int, int>>> adj(n+1); //1-indexed graph
    // edges are stored in {u, v, wt}.. u->v and v->u with wt weight (undirected grpah);
    vector<vector<int>> edges = {
        {1,2,2}, {2,5,5}, {1,4,1}, {4,3,3}, {3,5,1}, {3,2,4}};
    
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    int src = 1;
    vector<int> dist = dijkstra(adj, src);
    for (int i = 1; i<=n; i++){
        cout << "Distance from node " << src << " to node " << i << " is - " << dist[i] << endl;
    }
        return 0;
}