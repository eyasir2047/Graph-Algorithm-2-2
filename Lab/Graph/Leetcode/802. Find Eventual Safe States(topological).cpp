#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(int j: graph[i]) {
                //reversing the edges
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        //now as I reverse the edges, the node having indgree 0 is terminal node

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr: adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};