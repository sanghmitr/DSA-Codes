//Find the center node of the graph

#include<bits/stdc++.h>
using namespace std;

int main(){
	int M, N;
	cin>>M>>N;
	int graph[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			if(i==j){
				graph[i][j] = 0;
			}
			else graph[i][j] = -1;
		}
	}
	for(int i=0;i<N;i++){
		int x,y,d;
		cin>>x>>y>>d;
		graph[x-1][y-1] = d;
	}
	int solutionMatrix[M][M];
	
	
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			solutionMatrix[i][j] = graph[i][j];
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			if(solutionMatrix[i][j] == -1){
				solutionMatrix[i][j] = INT_MAX;
			}
		}
	}
	for(int k=0;k<M;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				if(solutionMatrix[i][k]!=INT_MAX && solutionMatrix[k][j]!=INT_MAX && (solutionMatrix[i][k] + solutionMatrix[k][j]) < solutionMatrix[i][j]){
					solutionMatrix[i][j] = solutionMatrix[i][k] + solutionMatrix[k][j];
				}
			}
		}
	}

	


	int solutionArray[M];
	for(int i=0;i<M;i++){
		int maximum = INT_MIN;
	for(int j=0;j<M;j++){
		if(solutionMatrix[j][i] > maximum){
			maximum = solutionMatrix[j][i];
		}
	}
	solutionArray[i] = maximum;
	}

	
	int minimum = INT_MAX;
	int minIndex = M;
	for(int i=0;i<M;i++){
		if(solutionArray[i] < minimum){
			minimum = solutionArray[i];
			minIndex = i;
		}
		else if(solutionArray[i] == minimum && i < minIndex){
			minIndex = i;
		}
	}
	cout<<minIndex+1;
}