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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort 
        int n=numCourses;
        vector<vector<int>>adj(n);

        for(int i=0;i<prerequisites.size();i++){
               adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }


     
       vector<int>indegree(n,0);
	    
	    for(int i=0;i<n;i++){
	        for(auto child:adj[i]){
	            indegree[child]++;
	        }
	    }
	    
	    // for(int i=0;i<n;i++){
	    //     cout<<i<<": "<<indegree[i]<<" "<<endl;
	    // }
	   
	    
	    
	     queue<int>q;
	     
	     for(int i=0;i<n;i++){
	         if(indegree[i]==0){
	             q.push(i);
	         }
	     }
	     
	     vector<int>ans;
	     
	     while(!q.empty()){
	         int node=q.front();
	         q.pop();
	         ans.push_back(node);
	         
	         for(auto child:adj[node]){
	             indegree[child]--;
	             if(indegree[child]==0){
	                 q.push(child);
	             }
	         }      
	     }
	    
        if(ans.size()==n)
       return ans;

       return {};



    }
};