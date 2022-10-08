class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<vector<int>> ans;
        for(int i=0;i<n ;i++ ){
            if(nums[i]>0) break;
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j< n ;j++){
                if(mp.find(-(nums[i]+nums[j]))!=mp.end() && mp.find(-(nums[i]+nums[j]))->second>j){
                    ans.push_back({nums[i], nums[j] , -(nums[i]+nums[j])});
                }
                j = mp.find(nums[j])->second;
            }
            i=mp.find(nums[i])->second;
        }
        return ans;
        
    }
};