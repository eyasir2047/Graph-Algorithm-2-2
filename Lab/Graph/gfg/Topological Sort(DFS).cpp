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

stack<int>st;

void dfs(int node){
	    vis[node]=1;
	  
	    
	    for(auto child: adj[node]){
	        
	        if(!vis[child]){
	       
	            dfs(child);
	         
	           
	        }
	    }
	    //cout<<node<<" ";
	    st.push(node);
	}
	    
	    

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
      for(int i=0;i<n;i++){
	        if(!vis[i]){
	            dfs(i);
	        }
	    }
	    
	    vector<int>ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	   // cout<<endl;
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
    cout<<endl;
    
        
        
        return 0;
    
}
