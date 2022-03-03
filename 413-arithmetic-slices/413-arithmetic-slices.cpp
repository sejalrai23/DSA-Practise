class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp[nums.size()];
        if(nums.size()<3){
            return 0;
        }
        if(nums[2]-nums[1]==nums[1]-nums[0]){
            dp[2]=1;
        }
        int res=dp[2];
        for(int i=3;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
            }else{
                dp[i]=0;
            }
            res+=dp[i];
        }
        return res;
        
    }
};