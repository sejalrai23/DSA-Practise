class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto it :operations){
            nums[mp[it[0]]]=it[1];
            mp[it[1]]=mp[it[0]];
        }
        return nums;
    }
};