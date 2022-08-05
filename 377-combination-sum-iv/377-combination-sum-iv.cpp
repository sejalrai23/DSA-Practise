class Solution {
public:
    
    int recur(vector<int>& nums , int target , int ind, int n, vector<int>& dp){
       if(target==0) return 1;
        
        if(ind>=n || target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        
        for(int i=0;i<n ;i++){
            if(nums[i]<=target){
                ans+=recur(nums , target-nums[i], i, n , dp);
            }
        }
        
         
        
        return dp[target]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1 , -1);
        return recur(nums , target , 0 , n, dp);
    }
};