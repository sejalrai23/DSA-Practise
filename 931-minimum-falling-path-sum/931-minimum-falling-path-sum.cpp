class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n=matrix.size();
        int m= matrix.size();
       vector<vector<int>> dp(n , vector<int>(m , INT_MAX));
        for(int i=0;i< m;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        
        for(int i=n-2;i>=0; i--){
            for(int j=0;j<m ;j++){
                int ans=INT_MAX;
                
                for(int k=j-1 ;k<=j+1;k++){
                    if(k>=0 && k<m){
                        ans=min(ans , dp[i+1][k]);
                    }
                }
                dp[i][j]=ans+matrix[i][j];
            }
        }
       return *min_element(dp[0].begin(),dp[0].end()); 
    }
};

