#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define rep(a,b) for(ll i=a;i<=b;i++)
#define INF (1LL<<60)
const int N=2e5+100;


vector<pair<ll,ll>>adj[N+10],adj2[N+10];//{u,{v,w}}
vector<pair<pair<ll,ll>,ll>>ans; //{{u,v},w}
ll dt[N+10];
ll dt2[N+10];

int main(){
    ll n,m;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj2[v].push_back({u,w});
        ans.push_back({{u,v},w});
    }
    
    po(i,n)dt[i]=INF;
    
    dt[1]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    
    pq.push({0,1});
    
    while(!pq.empty()){
        ll dist=pq.top().first;
        ll curr=pq.top().second;
        pq.pop();
        if(dist>dt[curr])continue;
        for(auto child:adj[curr]){
            ll adjNode=child.first;
            ll adjW=child.second;
            
            if(dist+adjW<dt[adjNode]){
                dt[adjNode]=dist+adjW;
                pq.push({dt[adjNode],adjNode});
            }
        }
    }
    //now the queue is empty, so we can use the same queue
    po(i,n)dt2[i]=INF;
    
    dt2[n]=0;
    
    pq.push({0,n});
    
     while(!pq.empty()){
        ll dist2=pq.top().first;
        ll curr2=pq.top().second;
        pq.pop();
        
        if(dist2>dt2[curr2])continue;
        
        for(auto child:adj2[curr2]){
            ll adjNode2=child.first;
            ll adjW2=child.second;
            
            if(dist2+adjW2<dt2[adjNode2]){
                dt2[adjNode2]=dist2+adjW2;
                pq.push({dt2[adjNode2],adjNode2});
            }
        }
    }
    
    
    ll mini=1e18+10;
    
    // po(i,n){
    //     cout<<dt[i]<<" ";
    // }
    // cout<<endl;
    // po(i,n){
    //     cout<<dt2[i]<<" ";
    // }cout<<endl;
    
    for(int i=0;i<m;i++){
        ll uu=ans[i].first.first;
        ll vv=ans[i].first.second;
        ll ww=ans[i].second;
       // cout<<uu<<" "<<vv<<" "<<ww<<endl;
       // cout<<dt[uu]+dt2[vv]+floor(ww/2)<<endl;
        mini=min(mini,dt[uu]+dt2[vv]+ww/2);
    }
    
    cout<<mini<<endl;
    
    
    
    
    return 0;
}