class Solution {
public:
    // int dp[101][101];
    bool recur(int n1 , int n2 , int n3 , string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(n1==s1.size() && n2==s2.size() && n3==s3.size()) return true;
        if(n1>s1.size() || n2>s2.size()) return false;
       
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        if( s1[n1]==s3[n3] && s2[n2]==s3[n3]){
            
             return dp[n1][n2]=recur(n1+1, n2 , n3+1 , s1, s2, s3, dp) || recur(n1, n2+1, n3+1 , s1, s2, s3, dp) ;
            
        }
        
        else if(s2[n2]==s3[n3]){
            
             return dp[n1][n2]=recur(n1, n2+1 , n3+1 , s1, s2, s3, dp);
            
        }else if( s1[n1]==s3[n3]){
            return dp[n1][n2]=recur(n1+1, n2 , n3+1 , s1, s2, s3, dp);
            
        }
            
        else {
            return false;
        }
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        // memset(dp, -1, sizeof(dp));
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return recur(0, 0, 0, s1, s2, s3, dp);
    }
};