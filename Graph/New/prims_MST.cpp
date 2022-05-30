#include<bits/stdc++.h>
using namespace std;

// O(N^2) time complexity because for each iteration we are finding the minimum
int prims_MST_brute(vector<vector<pair<int, int>>>&adj){
    int n = adj.size();

    vector<int> key(n, INT_MAX);
    vector<bool> mstset(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;
    parent[0] = -1;
    int mstcost = 0;

    for (int i = 0; i < n - 1; i++){ // Run outer loop n-1 times because MST should have exactly n-1 edges
        int mini = INT_MAX;
        int u;

        //Find out the minimum weight edge
        for (int j = 0; j<n; j++){
            if(mstset[j] == false and mini > key[j]){
                mini = key[j], u = j;
            }
        }

        //add the minimum Node into the MST
        mstset[u] = true;
    
        // For selected node 'u' traverse all adjacent and update their parent and keys
        for (auto p : adj[u])
        {
            int node = p.first;
            int wt = p.second;
            if(mstset[node] == false and wt < key[node]){
                parent[node] = u;
                key[node] = wt;
            }
        }
    }

    for (int i = 1; i < n; i++){
        cout << parent[i] << " -> " << i << " with weight : "<<key[i]<< endl;
        mstcost += key[i];
    }
    cout << "Minimum cost of MST is : " << mstcost << endl;
    return mstcost;
}

//Time complexity O((N+E)logE) using min-heap
int prims_MST_optimised(vector<vector<pair<int, int>>>&adj){
    int n = adj.size();

    vector<int> key(n, INT_MAX);
    vector<bool> mstset(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;
    parent[0] = -1;
    int mstcost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, 0});

    for (int i = 0; i < n - 1; i++){ // Run outer loop n-1 times because MST should have exactly n-1 edges
        if (pq.empty()) {
            cout << "No MST!" << endl;
            exit(0);
        }

        int u = pq.top().second;
        pq.pop();

        //add the minimum Node into the MST
        mstset[u] = true;
    
        // For selected node 'u' traverse all adjacent and update their parent and keys
        for (auto p : adj[u])
        {
            int node = p.first;
            int wt = p.second;
            if(mstset[node] == false and wt < key[node]){
                parent[node] = u;
                key[node] = wt;
                pq.push({wt, node});
            }
        }
    }

    for (int i = 1; i < n; i++){
        cout << parent[i] << " -> " << i << " with weight : "<<key[i]<< endl;
        mstcost += key[i];
    }
    cout << "Minimum cost of MST is : " << mstcost << endl;
    return mstcost;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    // edges are stored in {u, v, wt}.. u->v and v->u with wt weight;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1,2,3}, {1,4,5}, {1,3,8}, {2,4,7}
        };
    
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    int mincost = prims_MST_brute(adj);
    int mincost1 = prims_MST_optimised(adj);
    //cout << mincost << endl;
    return 0;
}