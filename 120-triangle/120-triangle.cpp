class Solution {
public:
 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m= triangle[n-1].size();
       vector<vector<int>> dp(n , vector<int>(m , INT_MAX));
        for(int i=0;i< m ;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0; i--){
            m--;
            for(int j=0;j<m ;j++){
                int ans=INT_MAX;
                for(int k=j ;k<=j+1;k++){
                    if(k>=0 && k<=m){
                        ans=min(ans , dp[i+1][k]);
                    }
                }
                dp[i][j]=ans+triangle[i][j];
            }
        }
        
       return *min_element(dp[0].begin(),dp[0].end());        
    }
};