#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<vector<int>>v;
	int r = n, c = n;
	if(n%2 == 0)
	{
		c /= 2;
		int cnt = 2;
		for(int i=0;i<r;i++)
		{
			vector<int>temp;
			for(int j=0;j<c;j++)
			{
				temp.push_back(cnt);
				cout<<cnt<<" ";
				cnt += 2;
			}
			v.push_back(temp);
			cout<<endl;
		}
	}
	else
	{
		int cnt = 1;
		for(int i=0;i<n;i++)
		{
			vector<int>temp;
			for(int j=0;j<n;j++)
			{
				cout<<cnt<<" ";
				temp.push_back(cnt++);
			}
			v.push_back(temp);
			cout<<endl;
		}
	}
	
	vector<int>op;


	int rbeg = 0, rend = r-1, cbeg = 0, cend = c-1;

	while(rbeg <= rend and cbeg <= cend)
	{
		// Go right
		for(int j=cbeg; j<cend; j++)
			op.push_back(v[rbeg][j]);
		
		rbeg++;

		//Go down
		for(int i=rbeg; i<rend; i++)
			op.push_back(v[i][cend]);
		cend--;

		//Go Left
		if(rbeg <= rend)
		{
			for(int j=cend; j>=cbeg; j--)
				op.push_back(v[rend][j]);
		}
		rend--;

		//Go up
		if(cbeg <= cend)
		{
			for(int i=rend; i>=rbeg; i--)
				op.push_back(v[i][cbeg]);
		}
		cbeg++;
	}

	if(n%2 == 1)
	{
		for(int i=0;i<op.size();i++)
		{
			if(op[i]%2 == 0)
				cout<<op[i]<<" ";
		}
	}
	else
	{
		for(int i=0;i<op.size();i++)
			cout<<op[i]<<" ";
	}
	cout<<endl;
}
