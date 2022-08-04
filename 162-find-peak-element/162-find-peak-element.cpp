class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++ ){
            if(i==0){
                if(nums[i]>nums[i+1]) return i;
            }
            else if(i==n-1){
                
                if(nums[n-1] >nums[n-2]) return n-1;
            }
            else{
                
                if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) return i;
            }
        }
        
        return -1;
    
    }
};