#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
class Solution {
public:

    bool dfs(int vertex,vector<bool>&color,vector<int>adj[],vector<int>&visited){
        
            visited[vertex]=1;
            
        for(auto child:adj[vertex]){
          
            if(!visited[child]){
            color[child]=!color[vertex];
            if(dfs(child,color,adj,visited)==false)return false;
            }
             else if(color[vertex]==color[child]) return false;
            
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool>color(V);
	    color[0]=0; 
	    vector<int>visited(V,0);
	   
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(!dfs(i,color,adj,visited)){
	             return false;
	         }
	        }
	    }
	    
	    return true;
	     
	    
	   
	}

};