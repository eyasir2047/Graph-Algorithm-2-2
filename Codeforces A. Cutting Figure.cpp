#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int i,int j,vector<string>&grid,vector<vector<int>>&vis,int n,int m){
   
    if(i<0 || j<0 || i>=n || j>=m)return;
    if(vis[i][j]==1)return;
    if(grid[i][j]=='.')return;
    vis[i][j]=1;

    dfs(i-1,j,grid,vis,n,m);
    dfs(i+1,j,grid,vis,n,m);
    dfs(i,j-1,grid,vis,n,m);
    dfs(i,j+1,grid,vis,n,m);
}
    int count_islands(vector<string>&grid,int n,int m){
        int cnt=0;
     
     
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
    }
    int minDays(int n,int m,vector<string>&grid) {
        int cnt=count_islands(grid,n,m);
        int k=0;
       // cout<<cnt<<endl;

        if(cnt>=2)return 0;

         

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                   k++;
                    grid[i][j]='.';
                    int cnt2=count_islands(grid,n,m);
                    if(cnt2>=2)return 1;
                    grid[i][j]='#';
                }
            }
        }
        
        if(k<=2)return -1;

        return 2;//else
    }
};

int main(){
    int n,m;
    cin>>n>>m;
 vector<string>g(n+1);
    for(int i=0;i<n;i++){
      cin>>g[i];
    }
    
    
    Solution obj;
    int ans;
   
     ans= obj.minDays(n,m,g);
   
    
    
    cout<<ans<<endl;
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<g[i][j];
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}