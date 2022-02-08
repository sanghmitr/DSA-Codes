#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    unordered_map<int, vector<int>>g;
    public:
        Graph(int n)
        {
            V = n;
        }
        void addEdge(int x, int y)
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        void DFS(int u, vector<int>&disc, vector<int>&low, vector<int>&parent, vector<bool>&articulation_point)
        {
            static int timer = 0;
            disc[u] = low[u] = timer;
            timer++;
            int children = 0;

            for(int v : g[u])
            {
                if(disc[v] == -1)  //If v is not visited
                {
                    children += 1;
                    parent[v] = u;
                    DFS(v, disc, low, parent, articulation_point);
                    low[u]= min(low[u], low[v]);

                    if(parent[u] == -1 and children > 1) //case-1 : U is root
                        articulation_point[u] = true;

                    if(parent[u] != -1 and low[v] >= disc[u]) //Case 2: Atleast 1 component will get separated
                        articulation_point[u] = true;
                }
                else if(v!=parent[u])  //ignore child to parent edge
                    low[u] = min(low[u], disc[v]);
            }
        }

        void find_Articulation_points()
        {
            vector<int>disc(V, -1), low(V, -1), parent(V, -1);
            vector<bool>articulation_point(V, false);

            for(int i=0;i<V;i++)
            {
                if(disc[i] == -1)
                    DFS(i, disc, low, parent, articulation_point);
            }
            cout<<"Articulation points are : ";
            for(int i=0;i<V;i++)
            {
                if(articulation_point[i] == true)
                    cout<<i<<" ";
            }
        }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(3,4);
    
    g.find_Articulation_points();
    return 0;    
}