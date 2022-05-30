#include<bits/stdc++.h>
using namespace std;

//Adjacency List
vector<vector<int>> adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool checkForCycle(int src, vector<bool>&visited)
{
    int n = adj.size();
    //Pair is  <node, parent>
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push({nbr, node});
            }
            // If the we came across this node via other node...other than its parent then there is another path exists in the graph.
            else if(parent != nbr)
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 12;
    adj.resize(n);

    //Add Edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(5, 10);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(10, 9);
    addEdge(9, 8);
    addEdge(8, 11);

    vector<bool> visited(n, false);
    bool cyclePresent = false;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(checkForCycle(i, visited))
            {
                cyclePresent = true;
                break;
            }  
        }
    }
    if(cyclePresent)
        cout << "Cycle found " << endl;
    else
        cout << "Cycle Not found" << endl;
    return 0;
}