
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;
    vector<int> visited;
    vector<int> disc;
    vector<int> low;
    int time;
    vector<vector<int>>ans;
    

public:
    Graph(int vertices) : V(vertices), adjList(vertices), visited(vertices, 0), disc(vertices, -1), low(vertices, -1), time(0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void findBridges() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }

    void dfs(int u, int parent) {
        visited[u] = 1;
        disc[u] = low[u] = time++;
        
        for (int v : adjList[u]) {
            if (v == parent) {
                continue; // Skip the edge to the parent.
            }
            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                  // cout << "Bridge: " << u << " - " << v << endl;
                   ans.push_back({u,v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void print(){
        for(auto i:ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int V, E;
   // cout << "Enter the number of vertices: ";
    cin >> V;
   // cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    //cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Bridges in the graph:\n";
    graph.findBridges();
    graph.print();

    return 0;
}
