// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int x , int y, int n , int m){
        if(x<0 || x>=n ||y<0 || y>=m) return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& grid , vector<vector<int>> & vis , int n , int m , int i , int j){
        if(!isValid(i, j ,n ,m ) || grid[i][j]=='0' || vis[i][j]==1) return ;
        vis[i][j]=1;
        // grid[i][j]='0';
        dfs(grid , vis , n , m , i+1, j);
         dfs(grid , vis , n , m , i, j+1);
          dfs(grid , vis , n , m , i-1, j);
           dfs(grid , vis , n , m , i, j-1);
        dfs(grid , vis , n , m , i+1, j+1);
         dfs(grid , vis , n , m , i-1, j-1);
          dfs(grid , vis , n , m , i-1, j+1);
           dfs(grid , vis , n , m , i+1, j-1);
           return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt=0;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j]=='1' && vis[i][j]==0 ){
                    dfs(grid, vis , n , m , i , j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends