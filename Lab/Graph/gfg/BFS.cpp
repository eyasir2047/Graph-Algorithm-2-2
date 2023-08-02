#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N];
int level[N];// shortest distance

int n,m;
vector<int>ans(n);

void bfs(int source){
    
        queue<int>q;
        q.push(source);
        visited[source]=1;
        
        while(!q.empty()){
            int curr=q.front();
           // cout<<curr<<" ";
           ans.push_back(curr);
            q.pop();
            for(auto child:g[curr]){
                if(!visited[child]){
                    
                q.push(child);
                visited[child]=1;
                level[child]=level[curr]+1;
                
                }
            }
        }
        
       // cout<<endl;
        
}

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    bfs(0);//bfs(starting node)
   
   for(int i=0;i<n;i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;
    
//    for(int i=1;i<=n;i++){
//        cout<<i<<":"<<level[i]<<endl;
//    }
    for(int i=0;i<n;i++){
        cout<<i<<":"<<level[i]<<endl;
      }
    
        
        
        return 0;
    
}
