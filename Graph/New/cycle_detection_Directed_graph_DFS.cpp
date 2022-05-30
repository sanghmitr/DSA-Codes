#include<bits/stdc++.h>
using namespace std;

bool checkforCycle(vector<int>adj[], int node, bool vis[], bool dfsVis[]){
    vis[node] = true;
    dfsVis[node] = true;

    for(int nbr : adj[node]){
        if(!vis[nbr]){
            if(checkforCycle(adj, nbr, vis, dfsVis))
                return true;
        }
        else if(dfsVis[nbr] and vis[nbr])
            return true;
    }
    dfsVis[node] = false;
    return false;
}
bool isCyclic(int n, vector<int>adj[]){
    bool vis[n], dfsVis[n];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));

    for (int i = 0; i < n; i++){
        if(!vis[i]){
            if(checkforCycle(adj, i, vis, dfsVis)){
                cout << "Cycle present" << endl;
                return true;
            }
        }
    }
    cout << "Cycle not present" << endl;
    return false;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 9;
    vector<int> adj[9];
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 6}, {6, 5}, {7, 2}, {7, 8}, {8, 9}, {9, 7}};
    for (auto e : edges){
        adj[e[0]].push_back(e[1]);
    }

    bool ans = isCyclic(n, adj);
    return 0;
}