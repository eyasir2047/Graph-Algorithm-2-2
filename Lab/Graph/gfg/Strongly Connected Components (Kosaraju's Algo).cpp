#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
//vector<vector<int>>ans;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[node]=1;
        //discovery time
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,vis,st,adj);
            }
        }
        //finishing time
        st.push(node);
    }
    
    void dfs3(int node,vector<int>&vis,vector<int>adjR[]){
  
         vis[node]=1;
        
        cout<<node<<" ";
         
        for(auto child: adjR[node]){
           
            if(!vis[child]){
                
                dfs3(child,vis,adjR);
            }
        }
       // cout<<node<<" ";
       
        
    }
    
   
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //kosaraju algorithm-> 1) sort according to time and store it into the stack
        //2) reverse the edge
        //3) again dfs and count the scc
        
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int>adjR[V];
        //i->child, now child->i
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto child:adj[i]){
                adjR[child].push_back(i);
            }
        }
         
        
        int scc=0;
        
      
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
         // cout<<node<<" ";
            if(!vis[node]){
                scc++;
             //   cout<<endl;
                dfs3(node,vis,adjR);
            }
        }
     //  cout<<endl;
        return scc;
        
        
        
    }

   

int main(){
    
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
    int a=kosaraju(n,adj);
    cout<<endl;
    cout<<a<<endl;
   
    
   
        
        
        return 0;
    
}
