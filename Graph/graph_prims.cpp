#include <bits/stdc++.h>
using namespace std;

class Graph
{
    //Adjacency list for graph
    vector<pair<int,int>>*l;
    int V;

    public:
        Graph(int n)
        {
            V = n;
            l = new vector<pair<int,int>>[n];
        }

        void addEdge(int x, int y, int w)
        {
            l[x].push_back({y, w});
            l[y].push_back({x, w});
        } 

        int prim_mst()
        {
            //Priority queue contains pair of {weight, index of destination node}, basically it will store the edge information
            //here remaining 2 parameters are used to make it min-heap, because in c++ by default priority queue is max-heap
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;

            //visited array that denotes whether a node has been included in MST or not;
            vector<bool>visited(V, false);
            int ans = 0;
            q.push({0,0}); // weight, node

            while(!q.empty())
            {
                //pick the edge with min weight
                auto best = q.top();
                q.pop();

                int weight = best.first;
                int to = best.second;
                if(visited[to] == true)
                {
                    //discard the edge, and continue;
                    continue;
                }
                ans += weight;
                visited[to] = true; // Node has been added in MST;

                //Add the new edges in the queue;
                for(auto x : l[to])
                {
                    if(!visited[x.first])
                    {
                        q.push({x.second, x.first});
                    }
                }
            }
            return ans;
        }

};

int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1, y-1, w);
    }
    cout<<g.prim_mst()<<endl;
    return 0;
}