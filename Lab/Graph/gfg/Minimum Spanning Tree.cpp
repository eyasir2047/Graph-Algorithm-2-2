//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	int parent[100000],size[100000];
	
	void make(int v){
	    parent[v]=v;
	    size[v]=1;
	}
	
	int find(int v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	void Union(int a,int b){
	    a=find(a);
	    b=find(b);
	    if(size[a]<size[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size[a]+=size[b];
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])//{0,{1,5}}
    {
       //kruskal algorithm 
       //vector pairs are sort according to the first element
       //{wt,{a,b}}-> this will sort according to the weight(wt) of the node
       
      vector<pair<int, pair<int, int>>> v;
       
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                
                v.push_back({wt,{i,adjNode}});
                
            }
        }
        
        sort(v.begin(),v.end());
        int cost=0;
        for(int i=0;i<V;i++){
            make(i);
        }
        
        for(auto it:v){
            int weight=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
            
            if(find(node1)==find(node2))continue;
            Union(node1,node2);
            cost+=weight;
            
        }
        
        return cost;
       
       
    }
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends