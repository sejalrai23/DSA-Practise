class Solution {
public:
    int recur(vector<int>& prices, int ind , int buy, vector<vector<int>> &dp, int fee){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int prof=0;
        if(buy){
            prof= max(-prices[ind]+recur(prices, ind+1 , 0,dp,fee), recur(prices, ind+1,1,dp,fee));
        }else{
           prof= max(prices[ind]-fee+recur(prices , ind+1 , 1,dp,fee), recur(prices, ind+1, 0,dp,fee));
        }
        return dp[ind][buy]=prof;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() , vector<int>(2,-1));
        return recur(prices, 0,1,dp,fee);
        
    }
   
};