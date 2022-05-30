// Kahn's Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int>>&adj){
    int n = adj.size();

    // Find indegree of each node
    vector<int> indeg(n, 0);
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++){
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    //Push all zero in-degree nodes into queue.
    for (int i = 0; i < n; i++){
        if(indeg[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto nbr : adj[node]){
            indeg[nbr]--;
            if(indeg[nbr] == 0)
                q.push(nbr);
        }
    }
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