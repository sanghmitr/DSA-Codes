#include<bits/stdc++.h>
using namespace std;

template<typename T>

//Minimum number of dice throws required to reach the destination 36
//Starting from the source. Find the shortest path as well
class Graph
{
    map<T, list<T>>l;
    public:

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    T bfs(T src, T dest)
    {
        map<T, int>dist;
        map<T, T>parent;
        queue<T>q;
    
        //All other nodes have distance INT_MAX except start node
        for(auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        //Distance of source is 0
        dist[src] = 0;
        parent[src] = src;
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
                    parent[nbr] = node;
                }
            }
        }
        //Print path from destination to source 
        T temp = dest;
        while(temp!=src)
        {
            cout<<temp<<"<--";
            temp = parent[temp];
        }  
        cout<<src<<endl;
        return dist[dest];
    }
};

int main()
{   
    //Input
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //Add edges to the graph
    Graph<int>g;
    
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j = i + dice;
            j += board[j];

            if(j<=36)
            {
                 g.addEdge(i,j);
            }
        }
    }
    g.addEdge(36,36);
    cout<<g.bfs(0,36)<<endl;

    return 0;
}