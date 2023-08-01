#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one 
	}
 
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}
 
	for(int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
		if(g[u][v] == INF) 
			g[u][v] = -1;
		cout << g[u][v] << endl;
	}
}