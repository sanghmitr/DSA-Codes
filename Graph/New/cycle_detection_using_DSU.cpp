#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v)
{
    for (int i = 0; i<v; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find_Par(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_Par(parent[v]);
}

void _union(int u, int v)
{
    u = find_Par(u);
    v = find_Par(v);
    if(u != v)
    {
        if(sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 12;
    make_set(n);

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 4},{3, 5}, {5, 10},
                                {5, 6}, {6, 7}, {7, 8}, {10, 9}, {9, 8}, {8, 11}};

    bool cycle = false;
    for(auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int x = find_Par(u);
        int y = find_Par(v);
        if(x == y)
        {
            cycle = true;
        }
        else{
            _union(u, v);
        }
    }

    if(cycle)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle is not present" << endl;
    return 0;
}