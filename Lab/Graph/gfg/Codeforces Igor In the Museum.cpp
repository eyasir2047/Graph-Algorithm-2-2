#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
pair<int,int>moves[4]={{-1,0},{1,0},{0,+1},{0,-1}};
vector<string>adj;
set<pair<int,int>>st;
int n,m;
int vis[1010][1010];
int cnt=0;

#define eyasir2047  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void dfs(int i,int j){
    st.insert({i,j});
    vis[i][j]=1;
    
    for(int k=0;k<4;k++){
        int r=i+moves[k].first;
        int c=j+moves[k].second;
        if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && adj[r][c]=='.'){
            dfs(r,c);
        }else if(r>=0 && r<n && c>=0 && c<m && adj[r][c]=='*')cnt++;
    }
    
}

int main(){
    eyasir2047 
    
    int q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        adj.push_back(s);
    }
    
    map<pair<int,int>,int>mp;
    
    //precomputing to avoid time limit exceed
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && adj[i][j]=='.'){
                st.clear();
                cnt=0;
                dfs(i,j);
                for(auto [x,y]:st){
                    mp[{x,y}]=cnt;
                }
                
            }
        }
    }
    
    for(int i=0;i<q;i++){
       int sr,sc;
       cin>>sr>>sc;
       sr--,sc--;
       cout<<mp[{sr,sc}]<<endl;
        
    }
    return 0;
}