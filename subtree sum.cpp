#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int subtree_sum[N];
int eventcount_sum[N];

void dfs(int vertex,int parent){
    
    subtree_sum[vertex]+=vertex;
    if(vertex%2==0)eventcount_sum[vertex]++;
    
    for(int child:g[vertex]){
        
        if(child==parent)return;
        dfs(child,vertex);
        
        subtree_sum[vertex]+=subtree_sum[child];
        eventcount_sum[vertex]+=eventcount_sum[child];
    }
    
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1,0);
    
    
    for(int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<" "<<eventcount_sum[i]<<endl;
    }
    // int q;
    // cin>>q;
    // while(q--){
    //     int x;
    //     cin>>x;
    //     cout<<subtree_sum[x]<<endl;
    //     cout<<eventcount_sum[x]<<endl;
    // }
    return 0;
}