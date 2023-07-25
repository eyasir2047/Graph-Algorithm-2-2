#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5+10;
ll n,k;
vector<ll>g[N];
vector<ll>vis(N,0);

void dfs(ll src){
	vis[src]=1;

	for(auto child:g[src]){
		if(!vis[child]){
			vis[child]=1;
			dfs(child);
		}
	}

}
int main() {
	cin>>n>>k;
	for(ll i=0;i<k;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
		
	}
	cout<<cnt<<endl;
	return 0;
	
	
	
}

