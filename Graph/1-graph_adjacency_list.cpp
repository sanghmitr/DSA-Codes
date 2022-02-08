#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l; //pointer to Array of lists
    public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; //Array of list is declared at runtime
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex "<<i<<"-> ";
            for(int nbr : l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.printAdjList();
    return 0;
}