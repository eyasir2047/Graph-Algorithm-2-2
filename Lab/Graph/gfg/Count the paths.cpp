//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int cnt=0;
void dfs(int curr,int tar,vector<vector<int>>&ans,vector<bool>&vis,vector<vector<int>>&graph,vector<int>&res){

        res.push_back(curr);

        if(curr==tar){
         
            ans.push_back(res);
            cnt++;
          
        }
        
        for(auto child:graph[curr]){
           if(!vis[child]){
               vis[child]=true;
                dfs(child,tar,ans,vis,graph,res);
               vis[child]=false;
            }
        }
       
        res.pop_back();
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	int V=n;
        vector<vector<int>>ans;
        vector<int>res;
        vector<bool>vis(V,false);
         vector<vector<int>> adj(V);
          for(int i=0;i<edges.size();i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
        dfs(s,d,ans,vis,adj,res);
        return cnt;
	    
	  
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends