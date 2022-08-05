class Solution {
public:
    
    int recur(vector<int>& nums , int target , int ind, int n, vector<vector<int>>& dp){
       if(target==0) return 1;
        
        if(ind>=n || target<0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int ans=0;
        
        for(int i=0;i<n ;i++){
            if(nums[i]<=target){
                ans+=recur(nums , target-nums[i], i, n , dp);
            }
        }
        
         
        
        return dp[ind][target]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
        return recur(nums , target , 0 , n, dp);
    }
};