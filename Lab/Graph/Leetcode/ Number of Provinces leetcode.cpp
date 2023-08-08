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

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs(child,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }

        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
        
    }
};