class Solution {
public:
    vector<int> ans;
    vector<int> shuff;
    Solution(vector<int>& nums) {
        ans=nums;
        shuff=nums;
    }
    
    vector<int> reset() {
        return shuff;
    }
    
    vector<int> shuffle() {
        next_permutation(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */