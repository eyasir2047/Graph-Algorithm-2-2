#include <bits/stdc++.h>
using namespace std;
 
int n, m, answer = 0;
char grid[1010][1010];
 
void  DFS (int i, int j) {
  if (i < 0) return;
  if (j < 0) return;
  if (i >= n) return ;
  if (j >= m) return;
  if (grid[i][j] == '#') return;
  
  grid[i][j]='#';
  
    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j-1);
    DFS(i,j+1);
 
}
 
 
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
      
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.') {
            answer++;
          DFS(i, j);
          
        }
      }
    }
    cout << answer << endl;
    return 0;
}