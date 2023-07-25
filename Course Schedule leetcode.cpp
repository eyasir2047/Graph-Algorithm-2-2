#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();//number of egdes
        vector<vector<int>>g(n);
        //topological sort 

        for(int i=0;i<m;i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indgree(n,0);

        for(int i=0;i<n;i++){
            for(auto child:g[i])indgree[child]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indgree[i]==0)q.push(i);
        }
        vector<int>ans;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);

            for(auto child:g[curr]){
                indgree[child]--;
                if(indgree[child]==0){
                    q.push(child);
                }
            }
        }

        if(ans.size()==n)return true;

        return false;



    }
};