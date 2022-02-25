class Solution {
public:
    int getMaximumGenerated(int n) {
        int nums[n+1];
        if(n==0 || n==1){
            return n;
        }
        nums[0]=0;
        nums[1]=1;
        int maxi=max(nums[0],nums[1]);
        for(int i=2;i<=n;i++){
            if(i%2==0){
                nums[i]=nums[i/2];
                maxi=max(maxi,nums[i]);
            }else{
                nums[i]=nums[(i-1)/2]+nums[(i+1)/2];
                maxi=max(maxi,nums[i]);
            }
            
        }
        return maxi;
        
    }
};