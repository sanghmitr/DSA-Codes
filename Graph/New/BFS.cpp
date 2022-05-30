#include<bits/stdc++.h>
using namespace std;

//Adjacency List
vector<vector<int>> adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void bfs()
{
    int n = adj.size();
    vector<int> visited(n, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int nbr : adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    adj.resize(n);

    //Add Edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(0, 2);
    addEdge(4, 3);
    addEdge(1, 3);
    addEdge(1, 4);

    bfs();
    return 0;
}


/*


*/