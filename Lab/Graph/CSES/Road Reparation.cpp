#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const ll N=1e7+10;
ll parent[N];
ll size2[N];
	
	void make(ll v){
	    parent[v]=v;
	    size2[v]=1;
	}
	
	int find(ll v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	void Union(ll a,ll b){
	    a=find(a);
	    b=find(b);
	    if(size2[a]<size2[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size2[a]+=size2[b];
	}
	
    
void getMinimumCost(ll n, ll m, vector<vector<ll>> &connections) {
  //	Write your code here.
  // coding ninjas
  //{u,v,w}
    vector<pair<ll, pair<ll, ll>>> v;
	//{wt,{u,v}}
		ll V=n;
 
	for(auto &it:connections){
		ll i=it[0];
		ll adjNode=it[1];
		ll wt=it[2];
		v.push_back({wt,{i,adjNode}});
	}
       
        
        
        sort(v.begin(),v.end());
        ll cost=0;
        for(ll i=1;i<=V;i++){
            make(i);
        }
        
		int numEdges=0;
        for(auto it:v){
            ll weight=it.first;
            ll node1=it.second.first;
            ll node2=it.second.second;
           
            if(find(node1)==find(node2))continue;
            Union(node1,node2);
            cost+=weight;
			numEdges++;
			
			}
 
		
		
        if(numEdges==n-1){
            cout<<cost<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
       
 
		
}
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj;
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    
    getMinimumCost(n,m,adj);
    return 0;
}