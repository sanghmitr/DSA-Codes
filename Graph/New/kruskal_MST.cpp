#include<bits/stdc++.h>
using namespace std;

int findPar(int v, vector<int>&parent){
    if(v == parent[v]){
        return v;
    }
    return (parent[v] = findPar(parent[v], parent));
}

void _union(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findPar(u, parent);
    v = findPar(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 7;
    //vector<vector<pair<int, int>>> adj(n);
    // edges are stored in {u, v, wt}.. u->v and v->u with wt weight;
    vector<vector<int>> edges = {
        {1,4,1}, {1,2,2}, {2,3,3}, {2,4,3}, {1,5,4}, {3,4,5}, {2,6,7}, {3,6,8}, {4,5,9}
        };

    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    // for(auto e : edges){
    //     cout << e[0] << " " << e[1] << " " << e[2] << endl;
    //     adj[e[0]].push_back({e[1], e[2]});
    //     adj[e[1]].push_back({e[0], e[2]});
    // }

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for(auto e : edges){
        if(findPar(e[0], parent) != findPar(e[1], parent)){
            cost += e[2];
            mst.push_back({e[0], e[1]});
            _union(e[0], e[1], parent, rank);
        }
    }

    cout << "Cost of MST is : " << cost<<endl;
    for(auto p : mst){
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}