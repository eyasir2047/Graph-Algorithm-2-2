#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int idx[N],vis[N];

vector<vector<pair<int,int>>>adj(N);
//{u,{v,index}}

vector<int>ans;

//euler circuit

void dfs(int node){
    while(idx[node]<adj[node].size()){
        pair<int,int>y=adj[node][idx[node]];
        idx[node]++;
        if(!vis[y.second]){
            vis[y.second]=1;//y.second=index
            dfs(y.first);//y.first=child
        }
    }
    ans.push_back(node);
}

int main(){
    int t=1;
    //cin>>t
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()%2!=0){
                cout<<"IMPOSSIBLE";//as a euler circuit ,there is no odd degree edge
                return 0;
            }
        }
        
        dfs(1);
        
        if(ans.size()!=(m+1)){
            cout<<"IMPOSSIBLE";
                return 0;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        
        
    
    }
    
    return 0;
}
