#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
int res[N+1];
vector<pair<int,int> > adj[N+1];

struct Edge{
    int u,v,w;
    int idx;
};

Edge edges[N];

bool cmp(Edge u,Edge v){
    return u.w<v.w;//ascending
}

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
	    
	 //clearing the graph
	adj[a].clear();
	adj[b].clear();
	vis[a] = vis[b] = false;
	
	
	if(a==b)return;
	
	 parent[b]=a;
	 size[a]+=size[b];
	}
	
void addEdge(int u , int v , int idx){
	u = find(u);
	v= find(v);
 
	if(u == v) return ;//already connected, so avoid 
 
	res[idx] = 1;//as we connect it, it will be 1 or 2, initially storing 1
	adj[u].push_back({v , idx});
	adj[v].push_back({u , idx});
}

int main(){
    int n,m;
    cin>>n>>m;
    
   for(int i=1;i<=n;i++)make(i);
   
   
   for(int i=1;i<=m;i++){
       cin>>edges[i].u>>edges[i].v>>edges[i].w;
       edges[i].idx=i;
   }
   
   sort(edges+1,edges+m+1,cmp);//1 base indexing
   
   
   int i=1;
   
   for(;i<=m;){
       int j;
       for(j=i;edges[i].w==edges[j].w;j++){
           addEdge(edges[j].u,edges[j].v,edges[j].idx);
       }
   }
   
   
   /*
   0->none
   1->at least one
   2-> any/part of every mst
   */
   
   for(int i=1;i<=m;i++){
		if(res[i] == 0) cout<<"none\n";
		else if(res[i] == 1) cout<<"at least one\n";
		else	cout<<"any\n";	//part of every mst
	}
   
   return 0;
    
}