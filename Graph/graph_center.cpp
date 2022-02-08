#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int d[n+1][n+1] = {0};
	int ecc[n+1] = {0};
	set<int>s;
	int radius = INT_MAX;
	int diameter = 0;

	for(int i=0;i<m;i++)
	{
		int x,y,dis;
		cin>>x>>y>>dis;
		d[x][y] = dis;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}

	//Floyyd-Warshell
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	//find eccentericity
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ecc[i] = max(ecc[i], d[i][j]);
		}
	}

	//Find radius and diameter
	for(int i=1;i<=n;i++)
	{
		radius = min(radius, ecc[i]);
		diameter = max(diameter, ecc[i]);
	}

	for(int i=1;i<n;i++)
	{
		if(ecc[i] == radius)
		{
			s.insert(i);
		}
	}
	cout<<radius<<" "<<diameter<<" ";
	if(!s.empty())
		cout<<*(s.begin())<<endl;
	return 0;
}
