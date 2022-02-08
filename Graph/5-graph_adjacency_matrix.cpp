#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int v;
    int **mat; // Declare a double pointer.
    Graph(int n)
    {
        this->v = n;
        mat = new int*[n];  // Declare memory block of size N
        for(int i=0;i<n;i++)
        {
            mat[i] = new int[n]; //Declare memory block of size N and assign pointer to it
            for(int j=0;j<n;j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    void addEdge(int x, int y)
    {
        mat[x][y] = 1;
        mat[y][x] = 1;
    }

    void print_adjMatrix()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dfs_helper(vector<bool>&visited, int src)
    {
        cout<<src<<" ";
        visited[src] = true;
        for(int i=0;i<v;i++)
        {
            if(mat[src][i] == 1 and !visited[i] )
                dfs_helper(visited, i);
        }
    }
    void dfs(int src)
    {
        vector<bool>visited(v,false);
        dfs_helper(visited, src);
    }

}; 

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.print_adjMatrix();
    g.dfs(0);
    return 0;
}