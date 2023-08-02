#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//int n,m;


void dfs(int curr,vector<vector<int>>&adj,vector<int>&dt,vector<int>&low,stack<int>&st,
	vector<bool>&instack,vector<vector<int>>&ans){
	    static int time=0;
	    dt[curr]=low[curr]=time;
	    time++;
	    st.push(curr);
	    instack[curr]=true;
	    
	    for(auto child:adj[curr]){
	        if(dt[child]==-1){
	            dfs(child,adj,dt,low,st,instack,ans);
	            low[curr]=min(low[curr],low[child]);
	        }
	       else if(instack[child]){//back edge condition->already visited+ present in the stack
	           low[curr]=min(low[curr],dt[child]);
	           cout<<"back edges: "<<curr<<" "<<child<<endl;
	       }
           else {//cross edge -> //already visited but not present in the stack 
           //else if(!instack[child])
           cout<<"cross edges: "<<curr<<" "<<child<<endl;

           }
	    }
	  
	    
	    if(low[curr]==dt[curr]){// curr is the head of SCC
	        vector<int>res;
	        while(st.top()!=curr ){
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        }
	        
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        sort(res.begin(),res.end());
	        ans.push_back(res);
	    }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<vector<int>>&adj)
    {
        //code here
        //tarjan's algorithm-> bridge, articulation point, strongly connected components and 
        // topological sort 
        vector<int>dt(V,-1);
        vector<int>low(V,-1);
        vector<bool>instack(V,false);
        stack<int>st;
       
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(dt[i]==-1){
                dfs(i,adj,dt,low,st,instack,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
   vector<vector<int>>ans;
   ans=tarjans(n,adj);

   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        if(j==ans[i].size()-1){
            cout<<ans[i][j];
            continue;
        }
        cout<<ans[i][j]<<" ";
    }
    cout<<",";
   }


   
    
   
        
        
        return 0;
    
}

