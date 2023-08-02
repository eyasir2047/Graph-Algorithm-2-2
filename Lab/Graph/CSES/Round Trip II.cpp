#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
 
vector<int> vis;
 
stack<int> st;
 
vector<bool> pathVis;
 
bool dfs(int u)
{
	vis[u] = true;
	st.push(u);
	pathVis[u] = true;
	for(auto child: g[u])
	{
		if(!vis[child])
			if(dfs(child))
				return true;
 
		if(pathVis[child])
		{
			st.push(child);
			return true;
			//no more dfs;
		}
	}
    st.pop();
	pathVis[u] = false;
	return false;
	//no cycle was detected
}
 
 
void visit_all()
{
	for(int u = 1; u <= n; ++u)
	{
		if(!vis[u])
		{
			if(dfs(u))
				break;
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	pathVis.resize(n+1);
	
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
	//	g[u].insert(v);
	g[u].push_back(v);
	}
	visit_all();
	if(st.empty())
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	vector<int> ans;
	int temp = st.top();
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
		if(ans.back() == temp and ans.size() != 1)
			break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
	
}