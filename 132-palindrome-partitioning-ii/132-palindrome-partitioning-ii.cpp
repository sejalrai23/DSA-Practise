class Solution {
public:
    bool isPalindrome(int i , int j, string &str, vector<vector<int>>& dp){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int recur(int i , int n , string& str, vector<int>& dp, vector<vector<int>> &dp1){
        if(i==n) return 0; //no partition 
        if(dp[i]!=-1) return dp[i];
        if(isPalindrome(i , n-1 , str  , dp1)) return dp[i]=1;
            
        int minCost=INT_MAX ;
        for(int j=i;j<n ;j++){
            if(isPalindrome(i , j , str, dp1)){
                int cost= 1+ recur(j+1 , n, str, dp, dp1);
                minCost=min(minCost, cost);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        vector<int> dp(s.length(), -1);
        vector<vector<int>> dp1(s.length(), vector<int>(s.length(),-1));
        int ans= recur(0 , s.length(), s , dp, dp1);
        // cout<<ans<<endl;
        return  ans-1; //ABC partition is done  A| B | C | then i==n is checked
        
    }
};