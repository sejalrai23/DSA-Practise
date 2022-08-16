
class Solution {
public:
    vector<vector<int>> ans;
    void recur(int ind , vector<int>  nums ){
       
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind ;i<nums.size();i++){
           if (i != ind && nums[i] == nums[ind]) continue;


            swap(nums[ind],nums[i]);
            recur(ind+1,nums);
            // swap(nums[i],nums[ind]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recur(0,nums);
        return ans;
    }
};