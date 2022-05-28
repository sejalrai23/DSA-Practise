class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()+1;i++){
            if(i==nums.size()){
                ans=i;
            }
            else if(nums[i]!=i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};