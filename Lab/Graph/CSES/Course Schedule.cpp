#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<int> degree;
//priority_queue<int, vector<int>, greater<int>> pq;
queue<int>pq;
vector<vector<int>> g;
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n+1);
	degree.resize(n+1);
 
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		++degree[v];
	}
 
	for(int i = 1; i <= n; ++i)
	{
		if(degree[i]==0)
			pq.push(i);
	}
	
	vector<int> ans;
	while(!pq.empty())
	{
		int u = pq.front();
		pq.pop();
		ans.push_back(u);
		for(auto child: g[u])
		{
			--degree[child];
			if(degree[child]==0) pq.push(child);
		}
	}
 
	if(ans.size() != n)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(auto it: ans)
			cout << it << " ";
	}
}