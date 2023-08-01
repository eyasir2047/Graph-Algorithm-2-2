#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
void dfs(int curr,int tar,vector<vector<int>>&ans,vector<bool>&vis,vector<int>g[],vector<int>&res){

        res.push_back(curr);

        if(curr==tar){
         
            ans.push_back(res);
          
        }
        
        for(auto child:g[curr]){
           if(!vis[child]){
               vis[child]=true;
                dfs(child,tar,ans,vis,g,res);
               vis[child]=false;
            }
        }
       
        res.pop_back();
    }
    
vector<vector<int>> allPathsSourceTarget(vector<int>g[],int V) {
       
        vector<vector<int>>ans;
        vector<int>res;
        vector<bool>vis(V,false);
        dfs(0,V-1,ans,vis,g,res);
        return ans;
    }
    
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        
     }
     
    vector<vector<int>>ans= allPathsSourceTarget(g,n);
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto x : g[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
    }
