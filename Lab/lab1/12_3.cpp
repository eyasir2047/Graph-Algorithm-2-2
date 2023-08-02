#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

const int N = 1e5+10;
vector<int> g[N];

bool vis[N];

int dt[N];
int ft[N];
int num = 0;
int com[N];
int cnt=0;

void dfs(int node) {
    vis[node] = true;
    num++;
    dt[node] = num;
   
  priority_queue<int, vector<int>, greater<int>> pq;//minheap
  pq.push(node);
    com[node]=cnt;
    
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
    for (auto child : g[u]) {
        
        com[child]=cnt;
        if (!vis[child]) {
            dfs(child);
            pq.push(child);
        }
    }
    }

    ft[node] = ++num;
    
    
    }

int main() {
    
    eyasir2047
    int n, m;
    cin >> n >> m;
    

   
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); 
    }

   
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
        
       for (int i = 0; i < n; i++) {
        cout << i << ": "<<com[i]<<" "<<dt[i]<<" "<<ft[i]<<endl;
       
        
    }
    


   return 0;     
}
