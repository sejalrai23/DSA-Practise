class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev=s;
        int n=s.length();
        reverse(s.begin(),s.end());
        int m=rev.length();  
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};