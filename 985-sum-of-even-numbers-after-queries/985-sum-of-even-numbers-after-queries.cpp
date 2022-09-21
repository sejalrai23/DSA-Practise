class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even=0;
        for(auto it:nums){
            if(it%2==0) even+=it;
        }
        vector<int> ans;
        for(auto it: queries){
            if((nums[it[1]]+it[0])%2==0){
                if(nums[it[1]]%2==0){
                    even= even - nums[it[1]] + nums[it[1]]+it[0];
                }else{
                    even += nums[it[1]]+it[0];
                }
            }else{
                if(nums[it[1]]%2==0){
                    even-=nums[it[1]];
                }
            }
            nums[it[1]]=nums[it[1]]+it[0];
            ans.push_back(even);
        }
        return ans;
    }
}; 