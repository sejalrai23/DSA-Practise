class Solution {
public:
    int lcs (int n , int m , string& s, string& t, vector<vector<int>>& dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s[n-1]==t[m-1]){
            return dp[n][m]= 1+ lcs(n-1 , m-1 , s ,t,dp);
        }
        return dp[n][m]= max(lcs(n-1, m , s, t,dp), lcs(n , m-1 , s, t,dp));
    }
    int minDistance(string word1, string word2) {
        int n= word1.length(), m= word2.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        int lcsCount=lcs(n , m , word1, word2, dp);
        return n + m - 2*lcsCount;
        
        
    }
};