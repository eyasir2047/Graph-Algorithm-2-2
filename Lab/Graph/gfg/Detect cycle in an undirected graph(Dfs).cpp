#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int>adj[],bool vis[],int node,int parent){
       vis[node]=1;
       
       for(auto child:adj[node]){
           if(!vis[child]){
               vis[child]=1;
               if(dfs(adj,vis,child,node))return true;
           }else if(child!=parent){//vis[child]==true
               return true;
           }
       }
       
       return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(dfs(adj,vis,i,-1))return true;
            }
        }
        return false;
    }
