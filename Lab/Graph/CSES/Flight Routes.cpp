#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define rep(a,b) for(ll i=a;i<=b;i++)
#define INF (1LL<<60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N=2e5+100;

vector<vector<pair<ll,ll>>>adj;
vector<vector<ll>>dt;

int main(){
    
    eyasir2047
    
    ll n,m,k;cin>>n>>m>>k;
    
    adj.resize(n+1);
    dt.resize(n+1);
    
    po(i,n){
        dt[i].resize(k);
        fo(j,k){
            dt[i][j]=INF;
        }
    }
    
    dt[1][0]=0;
    
    fo(i,m){
        ll u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
   
   pq.push({0,1});
   
   while(!pq.empty()){
       ll curr=pq.top().second;
       ll w=pq.top().first;
       pq.pop();
       
       if(w>dt[curr][k-1])continue;
       
       for(auto child: adj[curr]){
           ll adjnode=child.first;
           ll adjW=child.second;
           if(w+adjW<dt[adjnode][k-1]){
               dt[adjnode][k-1]=w+adjW;
               pq.push({dt[adjnode][k-1],adjnode});
               sort(dt[adjnode].begin(),dt[adjnode].end());
           }
       }
   }
   
   
   fo(i,k){
       cout<<dt[n][i]<<" ";
   }
   cout<<endl;
    
    
    
      
 
    
    return 0;
}