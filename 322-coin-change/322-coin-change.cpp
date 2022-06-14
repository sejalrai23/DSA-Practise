class Solution {
public:
    int recur(vector<vector<int>>& dp , int ind , int target, vector<int>& coins){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
       int notTake= recur(dp, ind-1 , target , coins);
       int take=INT_MAX;
       if(coins[ind]<=target){
           take= 1+recur(dp, ind , target-coins[ind], coins);
       }
        return dp[ind][target]= min(take , notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n , vector<int> (amount+1 , -1));
        int ans=recur(dp , n-1, amount , coins);
        if(ans>=1e9) return -1 ;
        return ans;
        
        
    }
};