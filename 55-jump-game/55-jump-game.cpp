class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach =0,i=0;
        
        
        while(i<nums.size()){
            
            reach=max(reach, i+nums[i]);
            
            if(reach>=nums.size()-1){
                return true;
            }
            
            if(i==reach ){
                if(nums.size()-1==reach){  // cases like [0]
                    return true;
                }
                return false;
            }
            i++;
            // cout<<reach<<endl;
                
            
        }
        return reach>=nums.size()-1;
        
    }
};