class Solution {
  public:
   int recur(int n , int m , string s , string t , vector<vector<int>> &dp){
       if(n<0) return m+1;
       if(m<0) return n+1;
       if(dp[n][m]!=-1) return dp[n][m];
       if(s[n]==t[m]){
           return dp[n][m] = 0+ recur(n-1 , m-1, s , t, dp);
       }
       return dp[n][m]= 1 + min(recur(n-1 , m , s, t , dp) ,min(recur(n , m-1 , s, t , dp),recur(n-1 , m-1 , s , t, dp)) );
       
   }
    int minDistance(string s, string t) {
        // Code here
        int n=s.length() , m=t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return recur(n -1, m-1 ,s , t, dp);
        
    }
};