#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    void dfs(int curr,int tar,vector<vector<int>>&ans,vector<bool>&vis,vector<vector<int>>&graph,vector<int>&res){

        res.push_back(curr);

        if(curr==tar){
         
            ans.push_back(res);
          
        }
        
        for(auto child:graph[curr]){
           if(!vis[child]){
               vis[child]=true;
                dfs(child,tar,ans,vis,graph,res);
               vis[child]=false;
            }
        }
       
        res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>ans;
        vector<int>res;
        vector<bool>vis(V,false);
        dfs(0,V-1,ans,vis,graph,res);
        return ans;
    }
};