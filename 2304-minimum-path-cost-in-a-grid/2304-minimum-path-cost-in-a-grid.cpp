class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m,0));
        for(int i=0;i<m ;i++){
            dp[n-1][i]=grid[n-1][i];
        }
        
        for(int i=n-2 ; i>=0; i--){
            for(int j=0;j<m ;j++){
                int ans=INT_MAX;
                for(int k=0;k<m ;k++){
                    ans=min(ans, dp[i+1][k]+moveCost[grid[i][j]][k]);
                }
                dp[i][j]=ans+grid[i][j];
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};