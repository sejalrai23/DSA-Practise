
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=-1;        
        int curr_min=INT_MAX;
        int i=0 , j=n-1;
        int cur_max = INT_MIN;

        
        while(j>=0 && i<n){
            if(curr_min>nums[j]) curr_min=nums[j];
            else if(nums[j]>curr_min) start=j;
            
            if(cur_max<nums[i]) cur_max=nums[i];
            else if(nums[i]<cur_max) end=i;
            
            j--;
            i++;
        }
        
        if(start==-1 || end==-1){ 
            return 0;
        }
        return end-start+1; 
    }
};