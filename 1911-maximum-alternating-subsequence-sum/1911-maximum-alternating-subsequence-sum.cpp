class Solution {
public:
    long long recur(vector<int>& nums , vector<vector<long long>>& dp , int ind ,int n , int add ){
        if(ind==n) return 0;
        if(dp[ind][add]!=-1) return dp[ind][add];
        long long maxsum=0;
        long long nottake= recur(nums , dp , ind+1 , n , add);
        if(add){
           maxsum= nums[ind] + recur(nums , dp , ind+1 , n , 1-add); 
        }else if(!add){
           maxsum= -nums[ind]+ recur(nums , dp , ind+1, n , 1-add);
        }
        return dp[ind][add]= max(maxsum , nottake);
        
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1 , vector<long long>(2 , -1));
        int add= 1;
        return recur(nums , dp , 0 , n , add);
        
    }
};