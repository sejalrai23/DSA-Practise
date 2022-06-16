class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][n+1];
        memset(dp , 0 , sizeof(dp));
        
        for(int i= n-1 ;i>=0 ;i--){
            for(int j= i-1 ; j>=-1 ;j--){
                int len = dp[i+1][j+1];
                if(j== -1 || nums[i]>nums[j]){
                    len=max(len , 1+ dp[i+1][i+1]);
                }
                dp[i][j+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};