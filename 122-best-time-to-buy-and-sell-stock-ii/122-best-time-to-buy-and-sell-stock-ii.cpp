class Solution {
public:
    
    int recur(vector<int>& prices, int ind , int buy, vector<vector<int>> &dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int prof=0;
        if(buy){
            prof= max(-prices[ind]+recur(prices, ind+1 , 0,dp), recur(prices, ind+1,1,dp));
        }else{
           prof= max(prices[ind]+recur(prices , ind+1 , 1,dp), recur(prices, ind+1, 0,dp));
        }
        return dp[ind][buy]=prof;
    }
    int maxProfit(vector<int>& prices) {
        // cout<<prices.size()<<endl;
        vector<vector<int>> dp(30001 , vector<int>(2,-1));
        // memset(dp, -1, size(dp));
        return recur(prices, 0,1,dp);
        
    }
};