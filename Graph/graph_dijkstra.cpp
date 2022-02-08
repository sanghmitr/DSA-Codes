#include<bits/stdc++.h>
using namespace std;


template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;
    public:
    void addEdge(T u, T v, int dist, bool bidir = false)
    {
        m[u].push_back({v,dist});
        if(bidir)
        {
            m[v].push_back({u,dist});
        }
    }

    void dijkstra(T src, T end)
    { 
        unordered_map<T, int>dist;
        for(auto j : m)
        {
           dist[j.first] = INT_MAX; 
        }
        set<pair<int, T>>s;
        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto childPair : m[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    T dest = childPair.first;
                    auto f = s.find({dist[dest],dest});
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + childPair.second;
                    s.insert({dist[dest], dest});
                }
            }
        }
        for(auto d : dist)
        {
            if(d.first == end)
            {
                cout<<d.second;
            }
        }
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>nodes;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nodes.push_back(x);
    }
    int e;
    cin>>e;
    Graph<int>g;
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g.addEdge(x, y, z);
    }
    int src,dest;
    cin>>src>>dest;
    g.dijkstra(src, dest);
    return 0;
}