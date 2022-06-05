class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX , maxi=INT_MIN, ans=1;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            if(maxi-mini > k ){
                ans++;
                mini=maxi;
            }
        }
        return ans;
        
    }
};