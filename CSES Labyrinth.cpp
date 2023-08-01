#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll n,m;
vector<vector<bool>>vis;
vector<vector<pair<ll,ll>>>path;//2D vector with pair
vector<pair<ll,ll>>moves={{-1,0},{1,0},{0,-1},{0,1}};
ll sx,sy,ex,ey;
 
bool isValid(ll x,ll y){
    if(x<0 || x>=n || y<0 || y>=m)return false;
    if(vis[x][y])return false;
    return true;
}
 
void bfs(){
    queue<pair<ll,ll>>q;
    q.push({sx,sy});
    while(!q.empty()){
        ll cx=q.front().first;
        ll cy=q.front().second;
        q.pop();
        for(auto mv:moves){
            ll childx=mv.first;
            ll childy=mv.second;
            if(isValid(childx+cx,childy+cy)){
                vis[childx+cx][childy+cy]=true;
                q.push({childx+cx,childy+cy});
                path[childx+cx][childy+cy]={childx,childy};
            }
        }
        
    }
    
}
 
int main(){
    cin>>n>>m;
    vis.resize(n);
    path.resize(n);
    for(ll i=0;i<n;i++){
        path[i].resize(m);
        vis[i].resize(m);
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                vis[i][j]=true;
            }
            if(c=='A'){
                sx=i;
                sy=j;
            }
            if(c=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    
    bfs();
    
    if(!vis[ex][ey]){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    
    vector<pair<int,int>>ans;
    pair<int,int>end={ex,ey};
    
    while(end.first!=sx || end.second!=sy){
        ans.push_back(path[end.first][end.second]);
        end.first-=ans.back().first;
        end.second-=ans.back().second;
    }
    
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    
    for(auto it:ans){
        if(it.first==-1 && it.second==0)cout<<"U";
        else if(it.first==+1 && it.second==0)cout<<"D";
        else if(it.first==0 && it.second==-1)cout<<"L";
        else if(it.first==0 && it.second==+1)cout<<"R";
    }
    cout<<endl;
    
    
    return 0;
}