//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        int n=V;
         vector <bool> vis(n+1,false);
          int source=S;
          vector<int>dt(n+1,1e9+10);
          dt[source]=0;
     //   priority_queue<int>pq;
     //{u,{v,w}}
     //vector<int>v;
     //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     //{distance,source}
     //priority_queue<datatype,vector<datatype>,comparator>
     
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});
          
         while(!pq.empty()){
         
              int node=pq.top().second;
              int dist=pq.top().first;
              pq.pop();
              if(!vis[node]){
                  
              vis[node]=true;
            
              for(auto child:adj[node]){
                  int adjNode=child[0];//{u,{v,w}}-> child->{v,w}
                  int edgeW=child[1];
                  
                  if(dist+edgeW<dt[adjNode]){
                    
                      dt[adjNode]=dist+edgeW;
                      pq.push({dt[adjNode],adjNode});
                  }
              }
              }
          }
          vector<int>ans;
          
          
          for(int i=0;i<n;i++){
              if(dt[i]<1e9+10){
                 // cout<<dt[i]<<" ";
                 ans.push_back(dt[i]);
              }
              else{
                  ans.push_back(-1);
                 // cout<<"-1"<<" ";
                  }
          }
          
          return ans;
          
          
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends