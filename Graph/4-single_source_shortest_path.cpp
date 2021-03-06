#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
    map<T, list<T>>l;
    public:

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, int>dist;
        queue<T>q;
    
        //All other nodes have distance INT_MAX except start node
        for(auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        //Distance of source is 0
        dist[src] = 0;
        q.push(src);

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

            for(int nbr : l[node])
            {
                if(dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }   
        //Print the distance to every node
        for(auto node_pair : l)
        {
            cout<<"Distance of node "<<node_pair.first<<" from src is- "<<dist[node_pair.first]<<endl;
        }
    }
};

int main()
{
    Graph<int>g;
    // g.addEdge(0,1);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);

    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    
    g.bfs(2);

    return 0;
}