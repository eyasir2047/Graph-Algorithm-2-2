#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int vis[N];

int n,m;
	    
//kahn's algorithm-> bfs	    

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
    int indegree[n]={0};
	    
	    for(int i=0;i<n;i++){
	        for(auto child:adj[i]){
	            indegree[child]++;
	        }
	    }
	    
	    // for(int i=0;i<n;i++){
	    //     cout<<i<<": "<<indegree[i]<<" "<<endl;
	    // }
	   
	    
	    
	     queue<int>q;
	     
	     for(int i=0;i<n;i++){
	         if(indegree[i]==0){
	             q.push(i);
	         }
	     }
	     
	     vector<int>ans;
	     
	     while(!q.empty()){
	         int node=q.front();
	         
	         q.pop();
	         ans.push_back(node);
	         
	         for(auto child:adj[node]){
	             indegree[child]--;
	             if(indegree[child]==0){
	                 q.push(child);
	             }
	         }
	     }
	    
     
     for(int i=0;i<n;i++){
         cout<<ans[i]<<" ";
     }
     cout<<endl;
        
        
        return 0;
    
}
