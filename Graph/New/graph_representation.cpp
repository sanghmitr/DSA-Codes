#include<bits/stdc++.h>
using namespace std;

// useful when numbering of nodes starts from 0 and they are continous
class Graph1
{
    int n;
    vector<vector<int>>g;

    Graph1()
    {
        g.resize(n);
    }
    void addEdge(int x, int y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void addDirectedEdge(int x, int y)
    {
        g[x].push_back(y);
    }
};

// useful when numbering of nodes starts from 0 and they are continous
// When we need to keep edge weights also
class Graph2
{
    int n;
    vector<vector<pair<int, int>>>g;

    Graph2()
    {
        g.resize(n);
    }
    void addEdge(int x, int y, int wt)
    {
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
    void addDirectedEdge(int x, int y, int wt)
    {
        g[x].push_back({y, wt});
    }
};

// Use when nodes numbering is not continous OR nodes having string or character names
class Graph3
{
    unordered_map<int, vector<int>> g;
    Graph3(){};

    void addEdge(int x, int y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void addDirectedEdge(int x, int y)
    {
        g[x].push_back(y);
    }
};
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}