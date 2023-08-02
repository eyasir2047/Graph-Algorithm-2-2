#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

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
       
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(dfs(adj,vis,i,-1))return true;
            }
        }
        return false;
    }
    
    int main(){
        
    cin>>n>>m;
    vector<int>g[n];
       
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       
}
    if(!isCycle(n,g))
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;


}
