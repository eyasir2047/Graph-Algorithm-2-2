
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (ll i = 0; i < n; i++)
#define po(i, n) for (ll i = 1; i <= n; i++)
#define rep(a, b) for (ll i = a; i <= b; i++)
//#define INF (1LL << 60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N = 2e5 + 100;
const int INF=1e10+10;

struct Edge {
    int a, b, w;
};

int n, m;
vector<Edge> v;

void solve() {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    vector<int>parent(n+1,-1);

    for (int i = 0; i < (n - 1); i++) {
       // bool any=false;
        for (Edge e : v) {
            if (dist[e.a] != INF ) {
               dist[e.b]=min(dist[e.b],dist[e.a]+e.w);
                parent[e.b]=e.a;
           //     any=true;
            }
        }
       //if(!any)break;
    }

    bool ans = false;

    for (Edge e : v) {
        if (dist[e.a] != INF && dist[e.a] + e.w < dist[e.b]) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "Negative Cycle present" << endl;
     } //else if(dist[n]==INF){//no path from 1 to n
    //     cout<<"No path"<<endl;
    // }
    else {
        po(i, n){
            if(dist[i]!=INF)cout<<dist[i]<<" ";
            else cout<<"30000"<<" ";
        }
        cout << endl;

        // vector<int>path;
        // for(int curr=n;curr!=-1;curr=parent[curr])
        // path.push_back(curr);

        // reverse(path.begin(),path.end());

        // for(auto it:path)
        // cout<<it<<" ";

        // cout<<endl;


    }
}

int main() {
    eyasir2047
    cin >> n >> m;
    
    v.resize(m+10);
    
    po(i, m) {
        cin >> v[i].a >> v[i].b >> v[i].w;
    }

    solve();
    
    return 0;
}
