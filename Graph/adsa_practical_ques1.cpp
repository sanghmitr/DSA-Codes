//Find the root node of the graph
//Implemented using topological sort

#include<bits/stdc++.h>
using namespace std;

int n, m, x, y;

int main(){
	int t;
	cin >> t;

	while(t--){
		cin >> n >> m;
		vector<int> g[n];
		vector<int> in(n, 0);

		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			--x, --y;

			g[x].push_back(y);
			++in[y];
		}

		int out = -1;
		queue<int> q;
		for(int i = 0; i < n; ++i){
			if(!in[i]){
				q.push(i);
				out = i;
			}
		}
		if(q.size() > 1){
			out = -1;
		}

		vector<int> topo;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			topo.push_back(x);
			for(auto y : g[x]){
				--in[y];
				if(!in[y]){
					q.push(y);
				}
			}
		}

		if(topo.size() != n || out == -1){
			puts("-1");
			continue;
		}

		cout << out + 1 << endl;
	}
}