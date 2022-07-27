class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int ans=0;
        for(int i=0;i<nums.size() ;i++){
           ans= ans^nums[i];
        }
        
        int pos=0;
        
        while((ans&1)==0){
            pos++;
            ans=ans>>1;
        }
        
        int mask = 1<<pos ;// we need to check set bit of elements at given position so we left shift 
         int nums1=0 , nums2=0;   
        for(int i=0;i<nums.size();i++){
            
            if((mask&nums[i]) > 0){
                nums1=nums1^nums[i];
            }
            
            else {
                nums2=nums2^nums[i];
            }
        }
        
        return {nums1 , nums2};
    }
};