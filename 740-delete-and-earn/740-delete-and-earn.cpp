class Solution {
public:
    int dp[20001];
    int maximise(vector<int>& nums , int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int curVal= nums[idx];
        int curSum=nums[idx];
        int i=idx+1;
        while(i<nums.size() && nums[i]==curVal){
            curSum+=nums[idx];
            i++;
        }
        while(i<nums.size() && nums[i]==curVal+1){
            i++;
        }
        return dp[idx]=max(curSum + maximise(nums , i) , maximise(nums , idx+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        sort(nums.begin(),nums.end());
        return maximise(nums,0);
        
    }
};