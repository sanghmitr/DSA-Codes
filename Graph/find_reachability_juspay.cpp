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
        //l[y].push_back(x);
    }

    void dfs_helper(T src, map<T,bool>&visited)
    {   //Recursive function that will traverse the graph

        //cout<<src<<" ";
        visited[src] = true;
        //Go to all nbrs of that node is not visited
        for(auto nbr : l[src])
        {
            if(!visited[nbr])
                dfs_helper(nbr, visited);
        }
        return;
    }
    int dfs(T src, T dest)
    {
        map<T,bool>visited;
        //Mark all the nodes as not visited in the beginning
        for(auto p : l)
        {
            visited[p.first] = false;
        }
        //Call the dfs_helper function
        dfs_helper(src, visited);
        if(visited[dest] == false)
            return 0;
        return 1;
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
        int x,y;
        cin>>x>>y;
        g.addEdge(x, y);
    }
    int src,dest;
    cin>>src>>dest;

    cout<<g.dfs(src, dest);

    return 0;
}