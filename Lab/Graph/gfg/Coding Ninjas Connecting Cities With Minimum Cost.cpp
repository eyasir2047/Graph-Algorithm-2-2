#include <bits/stdc++.h>
using namespace std;

int parent[10000],size[10000];
	
	void make(int v){
	    parent[v]=v;
	    size[v]=1;
	}
	
	int find(int v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	void Union(int a,int b){
	    a=find(a);
	    b=find(b);
	    if(size[a]<size[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size[a]+=size[b];
	}
	
    
int getMinimumCost(int n, int m, vector<vector<int>> &connections) {
  //	Write your code here.
  // coding ninjas
  //{u,v,w}
    vector<pair<int, pair<int, int>>> v;
	//{wt,{u,v}}
		int V=n;

	for(auto &it:connections){
		int i=it[0];
		int adjNode=it[1];
		int wt=it[2];
		v.push_back({wt,{i,adjNode}});
	}
       
        
        
        sort(v.begin(),v.end());
        int cost=0;
        for(int i=1;i<=V;i++){
            make(i);
        }
        
		int numEdges=0;
        for(auto it:v){
            int weight=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
           
            if(find(node1)==find(node2))continue;
            Union(node1,node2);
            cost+=weight;
			numEdges++;
			
			}

		
		
        return numEdges==n-1 ? cost: -1;
       

		
}