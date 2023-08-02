#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);

int n,m;
	

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        int n=V;
         vector <bool> vis(n+1,false);
          int source=S;
          vector<int>dt(n+1,1e9+10);
          dt[source]=0;
     
    
     
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

int main(){
     cin>>n>>m;
     vector<vector<int>>adj[n];
       
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
       adj[u].push_back({v,1});
       
}
    vector<int>ans=dijkstra(n,adj,0);
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=-1)
        cout<<i<<": "<<ans[i]<<" "<<endl;
        else
        cout<<i<<": "<<"Not Reachable"<<endl;
    }
    cout<<endl;
}
