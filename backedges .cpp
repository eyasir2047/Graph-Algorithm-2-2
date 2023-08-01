
#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS and find back edges
bool dfs(vector<vector<int>>& graph, int v, int parent, vector<bool>& visited,vector<int>&ans) {
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            if (dfs(graph, u, v, visited,ans))
                return true;
        } else if (u != parent) {
            return true; // Found a back edge
        }
    }

    return false;
}

// Function to find back edges in an undirected graph
bool hasBackEdges(vector<vector<int>>& graph, int n,vector<int>&ans) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(graph, i, -1, visited,ans))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since it's an undirected graph
    }
        vector<int>ans;
        
        hasBackEdges(graph,n,ans);
        for(auto it:ans)cout<<it<<" ";
    // if (hasBackEdges(graph, n,ans)) {
    //     cout << "The graph has back edges (contains cycles)." << endl;
    // } else {
    //     cout << "The graph does not have any back edges (is acyclic)." << endl;
    // }

    return 0;
}
 