#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//minimum path-> bfs
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>g[N];
vector<int>level(N,INF);



int n,m;

int bfs(int n){
    
    deque<int>q;
    q.push_front(1);
    level[1]=0;
    
    while(!q.empty()){
        int curr=q.front();
        q.pop_front();
            
        for(auto child: g[curr]){
                int ff=child.first;
                int wt=child.second;
                if(level[curr]+wt<level[ff]){
                    level[ff]=level[curr]+wt;
                    if(wt==1){
                        q.push_back(ff);
                    }else{
                        q.push_front(ff);
                    }
                }
                
        }
        
    }
    
    return level[n]==INF?-1:level[n];
    
    
    
}

int main() {
	// your code goes here
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    if(u==v)continue; //did not want self loop
	    g[u].push_back({v,0});
	    g[v].push_back({u,1});
	    
	}
	
	cout<<bfs(n)<<endl;
	
	return 0;
}
