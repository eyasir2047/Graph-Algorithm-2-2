#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int depth[N];
int height[N];

void dfs(int vertex,int parent){

    for(int child:g[vertex]){
        
        if(child==parent)return;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);

    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n-2;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<height[i]<<" "<<depth[i]<<endl;
    }

    return 0;
}