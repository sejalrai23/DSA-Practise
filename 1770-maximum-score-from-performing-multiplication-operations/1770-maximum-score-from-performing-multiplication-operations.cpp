class Solution {
public:
    int recur(vector<int>&nums , vector<int>& mult, int i , int j, int m, int k,  vector<vector<int>>& dp, int n){
        if( k==m) return 0;
        if(dp[i][k]!=INT_MIN) return dp[i][k];
        return dp[i][k]= max(nums[i]*mult[k]+ recur(nums , mult, i+1 , j , m ,k+1,dp, n), nums[j]*mult[k]+ recur(nums, mult , i , j-1 , m , k+1 , dp, n));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        int n=nums.size();
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , INT_MIN));
        return recur(nums , multipliers , 0 ,n-1, m , 0 , dp, n );
    }
};