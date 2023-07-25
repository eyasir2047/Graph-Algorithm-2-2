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
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        //{{row,col},time}
        //rotten oranges are in the queue
        queue<pair<pair<int,int>,int>>q;

        int cntFresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==2){
                   vis[i][j]=2;
                   q.push({{i,j},0});
               }else{
                   vis[i][j]=0;
               }
               if(grid[i][j]==1){
                   cntFresh++;
               } 
            }
        }

        int tmax=0;
        int cnt=0;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tmax=max(tmax,time);

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&
                vis[nrow][ncol]!=2){
                    vis[nrow][ncol]=2;
                    cnt++;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }

        if(cnt==cntFresh){
            return tmax;
        }
        return -1;


    }
};