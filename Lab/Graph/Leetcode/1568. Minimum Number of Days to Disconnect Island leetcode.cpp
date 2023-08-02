#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

class Solution {
public:
void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m)return;
    if(vis[i][j])return;
    if(grid[i][j]==0)return;
    vis[i][j]=1;

    dfs(i-1,j,grid,vis);
    dfs(i+1,j,grid,vis);
    dfs(i,j-1,grid,vis);
    dfs(i,j+1,grid,vis);
}
    int count_islands(vector<vector<int>>&grid){
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int cnt=count_islands(grid);

        if(cnt==0 || cnt>=2)return 0;

         int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                   
                    grid[i][j]=0;
                    int cnt2=count_islands(grid);
                    if(cnt2==0 ||cnt2>=2)return 1;
                    grid[i][j]=1;
                }
            }
        }

        return 2;//else
    }
};