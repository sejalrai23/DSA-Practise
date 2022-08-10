class Solution {
public:
    int getCost(vector<int>& days , vector<int> & cost , int ind , int n, vector<int>& dp){
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int oneDay= cost[0] + getCost(days , cost , ind+1 , n, dp);
        
        int i;
        for(i= ind ; i<n && days[i]<days[ind]+7 ;i++);
        
        int sevDay= cost[1]+ getCost(days , cost , i , n, dp);
        
        for(i= ind ; i<n && days[i]<days[ind]+30 ;i++);
        
        int thirtyDay= cost[2]+ getCost(days , cost , i , n, dp);
        
        return dp[ind]=min({oneDay , sevDay , thirtyDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+2 , -1);
        return getCost(days , costs , 0 , days.size() , dp);
    }
};