class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefSum=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            ans.push_back(prefSum);
        }
        return ans;
        
    }
};