#include <bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    int V;
    vector<int>*l;
    //int timer = 0;
        Graph(int n)
        {
            V = n;
            l  = new vector<int>[n];
        }

        void addEdge(int u, int v, bool isDir = true)
        {
            l[u].push_back(v);
            if(!isDir)
                l[v].push_back(u);
        }  

        void dfs_helper(int src, vector<bool>&visited, int &timer, vector<int>&time_in, vector<int>&time_out)
        {
            time_in[src] = ++timer;
            visited[src] = true;
            for(auto v : l[src])
            {
                if(!visited[v])
                    dfs_helper(v, visited, timer, time_in, time_out);
            }

            time_out[src] = ++timer; 
        }
        void dfs()
        {
            int timer = 0;
            vector<int>time_in(V, 0);
            vector<int>time_out(V, 0);
            vector<bool>visited(V, false);
            dfs_helper(0, visited, timer, time_in, time_out);

             //Find cross edges
            for(int i=0; i<V; i++)
            {
                cout<<time_in[i]<<" "<<time_out[i]<<endl;
            }
            cout<<"Cross edges: "<<endl;
            for(int u=0;u<V;u++)
            {
                for(auto v : l[u])
                {
                    if(time_in[u] > time_in[v] and time_out[u] > time_out[v])
                        cout<<u<<" -> "<<v<<endl;
                }
            }
        } 
};
int main()
{
    int n = 9;
    Graph g(n);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,7);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(3,5);
    g.addEdge(5,1);

    g.dfs();
    return 0;
}


/*

Tree edge:

arrival[u] < arrival[v]
departure[u] > departure[v]

Back edge:

arrival[u] > arrival[v]
departure[u] < departure[v]

Forward edge:

arrival[u] < arrival[v]
departure[u] > departure[v]

Cross edge:

arrival[u] > arrival[v]
departure[u] > departure[v]

*/