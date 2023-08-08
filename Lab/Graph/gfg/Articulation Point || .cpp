//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void dfs(int curr,bool vis[],vector<int>adj[],int dt[],int low[],vector<bool>&ap,int time,int par){
      vis[curr]=1;
      time++;
      dt[curr]=low[curr]=time;
       int children=0;
      
      for(auto child:adj[curr]){
          if(par==child)continue;
          else if(!vis[child]){
               dfs(child,vis,adj,dt,low,ap,time,curr);
              low[curr]=min(low[curr],low[child]);
              if(par!=-1 && dt[curr]<=low[child]){
                  ap[curr]=1;
              }
              children++;
          }
          else{//vis[child]
               low[curr]=min(low[curr],dt[child]);
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
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
        int parent=-1;
        int time=0;
        vector<bool>ap(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,dt,low,ap,time,parent);
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