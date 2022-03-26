#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>size;

void makeSet(int n)
{
    parent.resize(n);
    size.resize(n);
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        size[i] = 0;
    }
}

int findPar(int node)
{
    if(node == parent[node])
        return node;
    
    return parent[node] = findPar(parent[node]); //Path compression
}

void _union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(size[u] < size[v])
        parent[u] = v;
    else if(size[v] < size[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        size[u]++;
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    makeSet(8);

    _union(1,2);
    _union(4,5);
    _union(6,7);
    _union(2,3);

    cout<<"Parent of 2 is : "<<findPar(2)<<endl;
    cout<<"Parent of 3 is : "<<findPar(3)<<endl;
    cout<<"Parent of 5 is : "<<findPar(5)<<endl;
    cout<<"Parent of 7 is : "<<findPar(7)<<endl;

    if(findPar(2) == findPar(6))
        cout<<"2 and 6 belongs to same set"<<endl;
    else
        cout<<"2 and 6 does not belong to same set"<<endl;

    for(auto x : size)
        cout<<x<<" ";
    return 0;
}