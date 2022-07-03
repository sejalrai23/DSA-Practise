class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int mini=1, maxi=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                maxi=1+mini;
            }else if( nums[i]<nums[i-1]){
                mini=1+maxi;
            }
        }
        return max(mini, maxi);
    }
};