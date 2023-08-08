#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int curr,vector<int>adj[],bool vis[],int dt[],int low[],int time,int parent,  vector<vector<int>>&ans){
    vis[curr]=1;
    time++;
    dt[curr]=low[curr]=time;
    

    for(auto child:adj[curr]){
        if(parent==child)continue;
        else if(!vis[child]){
            dfs(child,adj,vis,dt,low,time,curr,ans);
            low[curr]=min(low[curr],low[child]);
            if(dt[curr]<low[child]){
                    ans.push_back({curr,child});
            }
        }
        else{//vis[child]
                low[curr]=min(low[curr],low[child]);//->articulation point
        }
    }
   

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int dt[n];
        int low[n];
        int time=0;
        bool vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        
        vector<vector<int>>ans;

        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,dt,low,time,-1,ans);
            }
        }
        return ans;

    }
};