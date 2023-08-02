#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void tarjanBiconnected(int v, int parent, int &time, vector<int>& disc, vector<int>& low, stack<pair<int, int>>& stk);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isBiconnected();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::tarjanBiconnected(int v, int parent, int &time, vector<int>& disc, vector<int>& low, stack<pair<int, int>>& stk) {
    int children = 0;
    disc[v] = low[v] = ++time;
    for (int u : adj[v]) {
        if (u == parent)
            continue;
        if (disc[u] == -1) {
            children++;
            stk.push({v, u});
            tarjanBiconnected(u, v, time, disc, low, stk);

            low[v] = min(low[v], low[u]);

            if (low[u] >= disc[v]) {
                // The edge (v, u) is a bridge.
                // Process the biconnected component.
                while (stk.top() != make_pair(v, u)) {
                    cout << stk.top().first << "-" << stk.top().second << " ";
                    stk.pop();
                }
                cout << stk.top().first << "-" << stk.top().second << " ";
                stk.pop();
                cout << endl;
            }
        } else if (disc[u] < disc[v]) {
            low[v] = min(low[v], disc[u]);
            stk.push({v, u});
        }
    }
}

bool Graph::isBiconnected() {
    vector<int> disc(V, -1), low(V, -1);
    stack<pair<int, int>> stk;
    int time = 0;

    tarjanBiconnected(0, -1, time, disc, low, stk);

    // Check if there are any remaining edges in the stack
    while (!stk.empty()) {
        cout << stk.top().first << "-" << stk.top().second << " ";
        stk.pop();
    }

    return true;
}

int main() {
    int V, E;
    //cout << "Enter the number of vertices: ";
    cin >> V;
   // cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    //cout << "Enter the edges (vertex pairs):\n";
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cout << "Biconnected components:\n";
    if (g.isBiconnected()) {
        cout << "The graph is biconnected.\n";
    } else {
        cout << "The graph is not biconnected.\n";
    }

    return 0;
}
