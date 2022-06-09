class Solution {
public:
    vector<vector<int>> ans;
    void findSubsets(int ind , vector<int>& nums, vector<int> ds){
      
            ans.push_back(ds);
       
     
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            // cout<<nums[i]<<end;
            ds.push_back(nums[i]);
            findSubsets(i+1, nums , ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());

        findSubsets(0, nums , ds);
        return ans;
    }
};