#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX 100050
ll n,m;
vector<bool>vis(MAX,false);
vector<vector<ll>>g(MAX);
vector<ll>parent(MAX,-1);
 
void bfs(){
     queue<ll>q;
     q.push(1);
     vis[1]=true;
     
     while(!q.empty()){
         auto node=q.front();
         q.pop();
         for(auto child:g[node]){
             if(!vis[child]){
                 vis[child]=true;
                 parent[child]=node;
                 q.push(child);
             }
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
    
    bfs();
    
    stack<ll>st;
    ll node=n;
    while(node!=-1){
        st.push(node);
        node=parent[node];
    }
    if(st.size()==1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<st.size()<<endl;
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
    
 
    
    
    return 0;
}