class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<abs(target) || (sum+abs(target))%2!=0 ){
            return 0;
        }
        sum= (sum+abs(target))/2;
        
        int dp[n + 1][sum + 1];
        
       for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(nums[i - 1] <= j)
                 dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                  dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][sum];
    }
    
};