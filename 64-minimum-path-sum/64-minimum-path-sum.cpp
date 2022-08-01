class Solution {
public:
    int dp[300][300];
    bool isValid(int i , int j , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        return true;
    }
    
    
    int dfs(int m , int n , int i , int j , vector<vector<int>>& vis, vector<vector<int>> & grid){
        if(!isValid(i , j , m , n) || vis[i][j]==1) return 1e7; 
        
        if(i==m-1 && j==n-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        vis[i][j]=1;
        
        int down=grid[i][j]+ dfs(m , n , i+1 , j, vis, grid);
        int right=grid[i][j]+ dfs(m , n , i, j+1, vis, grid);
        vis[i][j]=0;
        
        return dp[i][j]=min(right , down);
    }
    

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int m= grid.size();
        int n =grid[0].size();
        vector<vector<int>> vis(m ,vector<int>( n , 0));
        return dfs(m , n , 0, 0, vis, grid);
    }
};