// Bridges are those edges on removal it makes graph disconnected... or number of connected components in the graph increased

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void dfs(vector<vector<int>>&adj, int node, int parent, vector<bool> &visited, vector<int>&start, vector<int>&low, int &timer){

    visited[node] = true;
    start[node] = low[node] = timer++; //Capture discovery time

    for(int nbr : adj[node]){
        if(nbr == parent) continue; // Skip the parent edge

        if(visited[nbr] == true){
            low[node] = min(low[node], start[nbr]);
        }
        else{
            dfs(adj, nbr, node, visited, start, low, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] > start[node]){
                //This edge is a bridge
                ans.push_back({node, nbr});
            }
        }
    }
}
void find_bridges(int n, vector<vector<int>>&adj){
    vector<bool> visited(n, false);
    vector<int> start(n, -1), low(n, -1);
    int timer = 0;

    //Check for all connected components
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(adj, i, -1, visited, start, low, timer);
        }
    }

    for(auto e : ans){
        cout << e[0] << " " << e[1] << endl;
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 4;
    vector<vector<int>> adj(n);

    vector<vector<int>> edges = {{0, 1}, {1, 2 }, {2, 0}, {1, 3 }};
    for (auto e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    find_bridges(n, adj);

    return 0;
}