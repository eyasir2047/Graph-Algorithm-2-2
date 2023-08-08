
#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;

    //int count = 1;

    for (auto child : graph[node]) {
        //count += dfs(child, visited, graph);
        dfs(child,visited,graph);
    }

    visited[node] = false; // Reset visited for other paths
   // return count;
}

int numberOfTopologicalOrders(int N, vector<vector<int>>& graph) {
   
    vector<int> inDegree(N, 0);

      for(int i=0;i<N;i++){
	        for(auto child:graph[i]){
	            inDegree[child]++;
	        }
	    }

    vector<bool> visited(N, false);
    int ans = 0;

    // Start DFS from nodes with in-degree 0
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
          //  ans += dfs(i, visited, graph);
          ans++;
          dfs(i, visited, graph);
        }
    }

    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;

 
   vector<vector<int>>adj(N);
  
   for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }

    int numTopologicalOrders = numberOfTopologicalOrders(N, adj);
    cout << numTopologicalOrders << endl;

    return 0;
}
