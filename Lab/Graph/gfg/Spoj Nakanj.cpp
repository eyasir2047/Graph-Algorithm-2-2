#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9;

int level[8][8];
int visited[8][8];

int getX(string s){
    return s[0]-'a';
}

int getY(string s){
    return s[1]-'1';
}


vector<pair<int,int>>movements={
    {1,2},{-1,2},{1,-2},{-1,-2},
    {2,1},{-2,1},{2,-1},{-2,-1}
    
};

bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited[i][j]=0;
            level[i][j]=INF;
        }
    }
}

int bfs(string source,string des){
    
    int sourceX=getX(source);
    int sourceY=getY(source);
    int desX=getX(des);
    int desY=getY(des);
    
    reset();
    
    queue<pair<int,int>>q;
    q.push({sourceX,sourceY});
    visited[sourceX][sourceY]=1;
    level[sourceX][sourceY]=0;
    
    while(!q.empty()){
        pair<int,int>v=q.front();
        int x=v.first;
        int y=v.second;
        q.pop();
        
        
        for(auto movement: movements){
                int xx=movement.first+x;
                int yy=movement.second+y;
                
                if(!isvalid(xx,yy))continue;
        
                if(!visited[xx][yy]){
                    
                    q.push({xx,yy});
                    
                    visited[xx][yy]=1;
                    level[xx][yy]=level[x][y]+1;
                }
               
        }
        
        if(level[desX][desY]!=INF)break;
        
       
        
    }
    
    
    return level[desX][desY];
    
    
    
    
	
}





int main() {
	int n;
	cin>>n;
	
	while(n--){
		
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
		
	}
	
	

	return 0;
}