#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
//connected components in a graph
const int N=1e5+10;
vector<int>g[N];
bool visited[N];

void dfs(int vertex){

	visited[vertex]=true;
	

	for(auto child: g[vertex]){
		if(visited[child])continue;
		
		
		dfs(child);
	}
}


int main(){

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);

	}

	int cnt=0;
	for(int i=1;i<=n;i++){
		if(visited[i])continue;
		dfs(i);
		cnt++;
	}
	cout<<cnt<<endl;

	
}
