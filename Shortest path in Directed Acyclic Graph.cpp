//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int e, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0;i<e;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> topo;
        int indegree[n]={0};
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            indegree[it.first]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it.first]--;
                if(indegree[it.first]==0)
                q.push(it.first);
            }
        }
        vector<int> dist(n,1e9);
        int src=0;
        dist[src]=0;
        for(int i=0;i<n;i++){
            int node=topo[i];
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v])
                dist[v]=dist[node]+wt;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends