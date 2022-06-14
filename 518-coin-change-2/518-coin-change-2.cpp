class Solution {
public:
    
    int recur(int n , int target , vector<int> & coins , vector<vector<int>>& dp){
        if(n==0) return 0;
        if(target==0) return 1;
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        if(coins[n-1]<=target){
           return  dp[n][target]= recur(n-1 , target , coins , dp) + recur(n , target-coins[n-1], coins , dp);
        }
        return dp[n][target]= recur(n-1, target , coins , dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));
        return recur(n , amount , coins , dp);
        
    
    }
};