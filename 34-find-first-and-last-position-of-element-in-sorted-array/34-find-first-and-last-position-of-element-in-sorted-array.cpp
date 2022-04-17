class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int h=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==h){
            return {-1,-1};
        }
        return {l,h-1};
    }
};