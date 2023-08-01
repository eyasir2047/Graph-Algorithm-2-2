#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n,m;
void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis){
        int ro[] = {-1,0,1,0};
        int co[] = {0,-1,0,1};
        for(int ii=0;ii<4;ii++){
            int r = i + ro[ii];
            int c = j + co[ii];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[i][j]==1){
                vis[r][c] = 1;
                dfs(r,c,grid,vis);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                vis[i][0]=1;
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                vis[i][m-1]=1;
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                vis[0][j]=1;
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                vis[n-1][j]=1;
                dfs(n-1,j,grid,vis);
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                        cnt++;
                }
            }
        }
        return cnt;
    }
};