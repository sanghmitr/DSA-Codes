#include<bits/stdc++.h>
using namespace std;

//Adjacency List
vector<vector<int>> adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool checkForCycle(int src, vector<bool>&visited, int parent)
{
    visited[src] = true;

    for(auto nbr : adj[src])
    {
        if(!visited[nbr])
        {
            if(checkForCycle(nbr, visited, src) == true)
                return true;
        }
        //cycle exists
        else if(nbr != parent)
            return true;
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
    vector<int> parent(n, -1);
    bool cyclePresent = false;

    //Check for each component of a graph
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(checkForCycle(i, visited, -1))
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