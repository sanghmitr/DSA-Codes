#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N,X,Y;
		cin>>N>>M;
		vector<int>graph[N];
		vector<int> l(N,0);
		for(int i=0;i<M;i++)
		 { cin>>X>>Y;
		  --X,--Y;
		 
            graph[X].push_back(Y);
            ++l[Y];
		 }
		 int f=-1;
		 queue<int> q;
		 for(int i=0;i<N;i++)
		 {
			 if(!l[i])
			 {
				 q.push(i);
				 f=i;
			 }
		 }
		 if(q.size()>1)
		 {
			 f=-1;
		 }
		 vector<int> to;
		 while(!q.empty())
		 {
			 int X=q.front();
			 q.pop();
			 to.push_back(X);
			 for(auto Y:graph[X])
			 {
				 --l[Y];
				 if(!l[Y])
				 {
					 q.push(Y);
				 }
			 }
		 }
		 if(to.size()!=N || f==-1)
		 {
			 puts("-1");
			 continue;
		 }
		 cout<<f+1<<endl;
	}
}