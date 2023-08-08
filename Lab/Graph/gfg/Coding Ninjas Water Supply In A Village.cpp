#include<bits/stdc++.h>
using namespace std;
/*
vector<vector<int>> pipes = {{1, 2, 1}, {2, 3, 1}};
int u,v,w;
cin>>u>>v>>w;
vector<vector<int>>pipes;
pipes.push_back({u,v,w});
for (int i = 0; i < wells.size(); i++)
           pipes.push_back({0, i + 1, wells[i]});
sort(pipes.begin(),pipes.end(),cmp);

bool cmp(const vector<int>&v1,const vector<int>&v2){
		return v1[2]<v2[1];

}*/
class Uni{
	public:
int parent[100000];
int size[100000];
	
	void make(int v){
	    parent[v]=v;
	    size[v]=1;
	}
	
	int find(int v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}

	bool isconnected(int a,int b){
		return find(a)==find(b);//parent same means connected
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
};
	
int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// Write your code here.
	  //kruskal algorithm 
       //vector pairs are sort according to the first element
       //{wt,{a,b}}-> this will sort according to the weight(wt) of the node(first thing)

	   int V=n;
       
      vector<pair<int, pair<int, int>>> v;

		for(auto it:pipes){
			int i=it[0];
			int adjNode=it[1];
			int wt=it[2];
			v.push_back({wt,{i,adjNode}});
		}

		for(int i=0;i<wells.size();i++){
			v.push_back({wells[i],{0,i+1}});// 0 is not there, so I use 0 node.
		}
        
        sort(v.begin(),v.end());
			Uni un;
        int cost=0;
        for(int i=0;i<=V;i++){
           un. make(i);
        }
        
		
        for(auto it:v){
            int weight=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
            
            if(un. find(node1)==un.find(node2))continue;
            un.Union(node1,node2);
            cost+=weight;
		
            
        }

		return  cost;
        
        
       
       
}