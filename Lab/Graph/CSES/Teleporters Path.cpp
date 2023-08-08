#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<vector<pair<int,int>>>adj(N);
vector<int>ans;

int idx[N];
int out[N];
int vis[N];

//euler path

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
            out[u]++;
            out[v]--;
        }
        
        
    dfs(1);
   // cout<<out[1]<<" "<<out[n]<<" "<<ans.size()<<" "<<m+1<<endl;
        
    if(out[1]!=1 || out[n]!=-1 || ans.size()!=(m+1)){
        cout<<"IMPOSSIBLE"<<endl;
        // cout<<"1"<<endl;
        return 0;
    }
    
    for(int i=2;i<n;i++){
        if(out[i]!=0){
           cout<<"IMPOSSIBLE"<<endl;
         //  cout<<"2"<<endl;
            return 0; 
        }
    }
    
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
        
}
    
    
    return 0;
}