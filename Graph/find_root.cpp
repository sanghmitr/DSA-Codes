#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int src, dest;
};

class Graph
{
	public:
	vector<vector<int>>l;

	Graph(vector<Edge>const &edges, int n)
	{
		l.resize(n);
		for(auto &edge : edges)
		{
			l[edge.src].push_back(edge.dest);
		}
	}
};

void dfs(Graph const &graph, int u, vector<bool>&visited)
{
	visited[u] = true;
	for(int v : graph.l[u])
	{
		if(!visited[v])
		{
			dfs(graph, v, visited);
		}
	}
}

int findRoot(Graph const &graph, int n)
{
	vector<bool>visited(n);

	int v = 0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(graph, i, visited);
			v = i;
		}
	}
	fill(visited.begin(), visited.end(), false);

	dfs(graph, v, visited);
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			return -1;
		}
	}
	return v;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<Edge>edges(m);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			edges[i].src = x-1;
			edges[i].dest = y-1;
		}
		Graph graph(edges, n);

        

		int root = findRoot(graph, n);
		if(root == -1 )
			cout<<"-1"<<endl;
		else
			cout<<root+1<<endl;
	}
	return 0;
}
