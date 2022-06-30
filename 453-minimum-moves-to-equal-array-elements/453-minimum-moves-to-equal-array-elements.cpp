class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX, sum=0;
        for(auto it:nums){
            sum+=it;
            mini=min(mini,it);
        }
        return sum-mini*n;
    }
};