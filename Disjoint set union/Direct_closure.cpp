//https://binarysearch.com/problems/Direct-Closure

#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>_rank;

void makeDSU(int n)
{
    parent.resize(n);
    _rank.resize(n);

    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        _rank[i] = 0;
    }
}

int findPar(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = findPar(parent[node]); // path compression
}

void _union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(_rank[u] < _rank[v])
        parent[v] = u;
    else if(_rank[v] < _rank[u])
        parent[u] = v;
    else
    {
        parent[u] = v;
        _rank[u]++;
    }
}
vector<vector<int>> solve(vector<vector<int>>& graph) {
    int n = graph.size();
    makeDSU(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
            _union(i, graph[i][j]);
    }

    vector<vector<int>>ans(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(findPar(i) == findPar(j))
                ans[i][j] = 1;
        }
    }

    // for(int i = 0;i<n;i++)
    //     cout<<i<<" parent is : "<<parent[i]<<endl;
    return ans;
}
 
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
