class Solution {
public:
    
    void subsets(vector<vector<int>>& ans , int idx , vector<int>& nums , vector<int>& lev){
        if(idx==nums.size()){
            ans.push_back(lev);
            return;
        }
        lev.push_back(nums[idx]);
        subsets(ans,idx+1, nums , lev);
        lev.pop_back();
        subsets(ans,idx+1, nums , lev);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> lev;
        subsets(ans, 0 , nums, lev);
        return ans;
        
        
    }
};