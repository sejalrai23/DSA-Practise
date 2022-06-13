class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n ;i++){
            for(int j=0;j<=m ;j++){
                if(i==0) {
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
            }
        }
        
        for(int i=1;i<=n ;i++){
            for(int j=1;j<=m ;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }else{
                    dp[i][j]= 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        
        return dp[n][m];
        
        
    }
};