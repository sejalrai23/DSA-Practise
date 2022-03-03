class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        target/=2;
        // cout<<target<<endl;
        bool dp[nums.size()+1][target+1];
        for(int i=0;i<=nums.size();i++) dp[i][0] = true;
        
        for(int j=0;j<=target;j++) dp[0][j] = false;
        
        for(int i=1 ;i<=nums.size();i++){
            for(int j=1;j<=target;j++){
                 if(nums[i-1]<=j){
                        dp[i][j]= dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
            }
        }
        return dp[nums.size()][target];
        
    }
};