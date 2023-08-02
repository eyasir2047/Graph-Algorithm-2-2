#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int sv, ev;//sv=starting vertex,ev=ending vertex
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 
 
bool dfs(int u, int par)
{
	vis[u] = true;
	parent[u] = par;
	for(auto child: g[u])
	{
		if(child == par) continue;
		if(!vis[child]) {
			if(dfs(child,u)) 
				return true;
		}
				
	   else if(vis[child]) //if vis[child] and that is not a parent, that means there
	   //is a cycle present there
		{
			sv = child; //starting vertex
			ev = u; //ending vertex
			return true;
		} 
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int i = ev;
	vector<int> ans;
	ans.push_back(ev);
	while(i != sv)
	{
		ans.push_back(parent[i]);
		i = parent[i];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for(auto it: ans)
	{
		cout << it << " ";
	}
 
}