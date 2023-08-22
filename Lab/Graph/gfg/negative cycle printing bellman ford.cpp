
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (ll i = 0; i < n; i++)
#define po(i, n) for (ll i = 1; i <= n; i++)
#define rep(a, b) for (ll i = a; i <= b; i++)
//#define INF (1LL << 60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N = 2e5 + 100;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main() {
    eyasir2047
    cin >> n >> m;
    
    edges.resize(m+10);
    
    po(i, m) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }

    solve();
    
    return 0;
}
