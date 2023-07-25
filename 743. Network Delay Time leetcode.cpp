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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
       // Code here
        //{u,{v,w}} and {v,{u,w}}//adjacency list
        //and for priority_queue-> {{x1,y1},{x2,y2},{x3,y3}}
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
            //adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dt(n+1,1e9);
        vector<int>parent(n+1);
       // vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int source=k;
        dt[source]=0;
        pq.push({0,source});
      //  visited[source]=true;
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
          //  if(!visited[node]){
               // visited[node]=true;
            for(auto child:adj[node]){
                int adjNode=child.first;
                int edgeW=child.second;
                if(edgeW+dist<dt[adjNode]){
                    dt[adjNode]=dist+edgeW;
                    pq.push({dt[adjNode],adjNode});
                    parent[adjNode]=node;
                }
           // }
            }
        }
        
        if(dt[n]==1e9)return -1;
        
     
      int maxi=0;
      for(int i=1;i<=n;i++){
          if(dt[i]==1e9)return -1;
          maxi=max(dt[i],maxi);
      }
        
     
      
        return maxi;
    }
};