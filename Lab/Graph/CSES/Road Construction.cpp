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
	
	bool Union(ll a,ll b){
	    a=find(a);
	    b=find(b);
	    if(a==b)return false;
	    if(size2[a]<size2[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size2[a]+=size2[b];
	    return true;
	}
	
 
int main(){
    ll n,m;
    cin>>n>>m;
    
    for(ll i=1;i<=n;i++)make(i);
    
   ll components=n;
   ll maxi=1;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        if(Union(u,v)){
            components--;
            maxi=max(maxi,size2[parent[u]]);
            maxi=max(maxi,size2[parent[v]]);
        }
        cout<<components<<" "<<maxi<<endl;
        
    }
    
   
    return 0;
}