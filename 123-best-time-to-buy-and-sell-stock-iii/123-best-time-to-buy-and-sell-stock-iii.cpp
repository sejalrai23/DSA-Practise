class Solution {
public:
    
    int recur(vector<int>& prices, int ind , int buy, vector<vector<vector<int>>> &dp,int cnt){
        if(ind==prices.size() || cnt==2 ){
            return 0;
        }
        if(dp[ind][buy][cnt]!=-1){
            return dp[ind][buy][cnt];
        }
        int prof=0;
        if(buy){
            prof= max(-prices[ind]+recur(prices, ind+1 , 0,dp,cnt), recur(prices, ind+1,1,dp,cnt));
        }else{
           prof= max(prices[ind]+recur(prices , ind+1 , 1,dp,cnt+1), recur(prices, ind+1, 0,dp,cnt));
        }
        return dp[ind][buy][cnt]=prof;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(2, vector<int>(3,-1)));
        int cnt=0;
        return recur(prices, 0,1,dp,cnt);
        
    }
};