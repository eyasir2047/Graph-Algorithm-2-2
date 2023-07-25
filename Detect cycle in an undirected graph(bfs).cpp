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
    
    bool detect(vector<int>adj[],bool vis[],int src){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto child: adj[node]){
                if(!vis[child]){
                    vis[child]=1;
                    q.push({child,node});
                }else if(parent!=child){
                    return true;
                }
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(detect(adj,vis,i))return true;
            }
        }
        return false;
    }
