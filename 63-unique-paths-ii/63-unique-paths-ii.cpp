class Solution {
public:
    int dp[102][102];
    bool isValid(int i , int j , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        return true;
    }
    
    
    int dfs(int m , int n , int i , int j , vector<vector<int>>& vis, vector<vector<int>>& obs){
        if(!isValid(i , j , m , n) || vis[i][j]==1 || obs[i][j]==1) return 0; 
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=1;
        int down= dfs(m , n , i+1 , j, vis, obs);
        int right= dfs(m , n , i, j+1, vis, obs);
        vis[i][j]=0;
        return dp[i][j]=right+down;
    }
    


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         memset(dp , -1 , sizeof(dp));
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> vis(m ,vector<int>( n , 0));
        return dfs(m , n , 0, 0, vis, obstacleGrid);
    }
};