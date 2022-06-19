class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0 , j=nums.size()-1;
        while(i<j){
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j--;
                
            }else if(nums[i]==val && nums[j]==val){
                j--;
                
            }else{
                i++;
            }
        }
        
        for(int i=nums.size()-1 ; i>=0 ; i--){
            if(nums[i]==val){
                nums.pop_back();
            }else{
                break;
            }
        }
        return nums.size();
    }
};