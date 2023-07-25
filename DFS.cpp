#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
bool visited[N];
 int n,m;
 vector<int>ans(n);


void dfs(int vertex){
    //
   visited[vertex]=true;
   ans.push_back(vertex);
  // cout<<vertex<<" ";
    for(auto child:g[vertex]){
        //cout<<vertex<<" "<<child<<endl;
        
        if(!visited[child]){
            //
             dfs(child);
             //
        }
    
    }
    //
    
}

int main(){
   
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       
}
           
            dfs(0);
            
            
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

 return 0;
}
