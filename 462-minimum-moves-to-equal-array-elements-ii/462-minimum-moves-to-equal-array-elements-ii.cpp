class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
        int ans=0, n=nums.size();
        sort(nums.begin(),nums.end());
        int med=nums[n/2];
        for(auto it : nums){
           
            ans+= abs(it-med);
            
        }

        return ans;
        
    }
};