#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

  bool dfs(int node,int  vis[],int pathVis[],vector<int>adj[]){
      vis[node]=1;
      pathVis[node]=1;
      
      for(auto child:adj[node]){
          if(!vis[child]){
              if(dfs(child,vis,pathVis,adj)==true)return true;
          }
          //visited and same path
          else if(pathVis[child]){
              return true;
          }
      }
      
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return true;
            }
        }
        
        return false;
    }
