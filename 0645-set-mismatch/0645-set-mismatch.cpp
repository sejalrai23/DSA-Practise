class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xor1=nums[0];
        
        for(int i=1;i<nums.size();i++){
            xor1=xor1^nums[i];
        }
        int n=nums.size();
        for(int i=1;i<=n ;i++){
            xor1=xor1^i;
        }
        
        int num= xor1 & ~(xor1-1);
        int x=0 , y=0;
        for(int i=0;i<n ;i++){
            if(nums[i]&num){
                x=x^nums[i];
            }else{
                y=y^nums[i];
            }
        }
        
        for(int i=1;i<=n ;i++){
            if(i&num){
                x=x^i;
            }else{
                y=y^i;
            }
        }
        for(auto it: nums){
            if(it==x){
                return {x, y};
            }
        }
        return {y,x};
    }
   
};