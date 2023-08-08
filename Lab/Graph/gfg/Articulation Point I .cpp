//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int curr,bool vis[],vector<int>adj[],int dt[],int low[],int time,int par,vector<int>&ap){
      vis[curr]=1;
      time++;
      dt[curr]=low[curr]=time;
      int children=0;
      
      for(auto child: adj[curr]){
          if(par==child)continue;
          else if(vis[child]){
              low[curr]=min(low[curr],dt[child]);
          }else{// !vis[child]
              dfs(child,vis,adj,dt,low,time,curr,ap);
              low[curr]=min(low[curr],low[child]);
              if(dt[curr]<=low[child] && par!=-1){
                 ap[curr]=1;
              }
              children++;
          }
      }
      
      if(par==-1 && children>1){
       ap[curr]=1;
      }
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int dt[V];
        int low[V];
        int time=0;
        int parent=-1;
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
       vector<int>ap(V,0);
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,dt,low,time,parent,ap);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(ap[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends