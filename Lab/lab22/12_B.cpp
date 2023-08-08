
#include <bits/stdc++.h>
using namespace std;
static int cnt=0;

class Graph
{
	int V; 
	list<int> *adj;
	vector<int> indegree;
void ans(vector<int>& res,bool visited[]);

public:
	Graph(int V); 
	void addEdge(int v, int w);
	void sort();
};


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	for (int i = 0; i < V; i++)
		indegree.push_back(0);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
	indegree[w]++;
}


void Graph::ans(vector<int>& res,bool visited[])
{
	
	bool flag = false;

	for (int i = 0; i < V; i++)
	{
		
		if (indegree[i] == 0 && !visited[i])
		{
		
			list<int>:: iterator j;
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]--;

			
			res.push_back(i);
			visited[i] = true;
			ans(res, visited);

			
			visited[i] = false;
			res.erase(res.end() - 1);
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]++;

			flag = true;
		}
	}

	
	if (!flag)
	{
		cnt++;
		
	}
}


void Graph::sort()
{
	
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	vector<int> res;
	ans(res, visited);
}


int main()
{
	int n,m;
	cin>>n>>m;

	Graph g(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	// int kk=1;
    //      for(auto i:l){
    //         if(i.second>1){
    //             //kk*=i.second;
    //             kk++;
    //         }
    //      }
        
    // cout<<kk<<endl;

    //    for(auto i:v){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl; 
    //    }
    //    int k=cnt; 
    //  for(auto i:mp){
    //         k*=i.second;
    //  }
    //  cout<<k<<endl;
    //  for(int i=0;i<n;i++){
    //      cout<<ans[i]<<" ";
    //  }

     //cout<<cnt<<endl;
    // cout<<endl;
	
	g.sort();
	cout<<cnt<<endl;

	return 0;
}
