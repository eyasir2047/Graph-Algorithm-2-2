//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
   int cnt=0;
  void dfs(int curr,vector<bool>&vis,vector<int>adj[],int tar){
     
      if(curr==tar){
         cnt++;
       
      }
      
      for(auto child:adj[curr]){
          if(!vis[child]){
              vis[child]=true;
              dfs(child,vis,adj,tar);
              vis[child]=false;
          }
      }
      
  }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool>vis(V,false);
        
        dfs(source,vis,adj,destination);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends