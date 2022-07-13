// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
     bool isValid(int x , int y, int n , int m){
        if(x<0 || x>=n ||y<0 || y>=m) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid , vector<vector<int>> & vis , int n , int m , int i , int j, int& cnt){
        if(!isValid(i, j ,n ,m ) || grid[i][j]==0 || vis[i][j]==1) return ;
        vis[i][j]=1;
        // grid[i][j]='0';
        cnt++;
        dfs(grid , vis , n , m , i+1, j, cnt);
         dfs(grid , vis , n , m , i, j+1, cnt);
          dfs(grid , vis , n , m , i-1, j, cnt);
           dfs(grid , vis , n , m , i, j-1, cnt);
        dfs(grid , vis , n , m , i+1, j+1, cnt);
         dfs(grid , vis , n , m , i-1, j-1, cnt);
          dfs(grid , vis , n , m , i-1, j+1, cnt);
           dfs(grid , vis , n , m , i+1, j-1, cnt);
           return;
    }
    int  findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int maxi=0;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j]==1 && vis[i][j]==0 ){
                    int cnt=0;
                    dfs(grid, vis , n , m , i , j, cnt);
                    maxi=max(maxi, cnt);
                }
            }
        }
        return maxi;
        
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends