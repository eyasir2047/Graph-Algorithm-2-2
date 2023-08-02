#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX 100050
ll n,m;
ll cc=0;
vector<bool>vis(MAX,false);
vector<vector<ll>>g(MAX);
 
 
void dfs(ll node){
    vis[node]=1;
    for(auto child:g[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
 
 
int main(){
    cin>>n>>m;
    
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
  vector<ll>ans;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            cc++;
            ans.push_back(i);
            dfs(i);
        }
    }
    
    cout<<cc-1<<endl;
  
    if(cc>1){
       for(ll i=0;i<ans.size()-1;i++){
           cout<<ans[i]<<" "<<ans[i+1]<<endl;
       }
    }
  
   
    
    
    return 0;
}