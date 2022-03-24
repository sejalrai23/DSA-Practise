class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1 , sum=0;
        while(i<=j){
            sum=max(sum , nums[i]+nums[j]);
            i++;
            j--;
        }
        return sum;
        
    }
};