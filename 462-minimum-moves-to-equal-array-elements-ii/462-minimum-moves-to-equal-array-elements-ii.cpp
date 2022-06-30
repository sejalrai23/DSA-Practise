class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
        int ans=0, n=nums.size(), med=0;
        sort(nums.begin(),nums.end());
        if(n%2!=0){
             med=nums[n/2];
        }else{
            med= (nums[(n-1)/2]+ nums[((n-1)/2)+1])/2;
        }
      
        for(auto it : nums){
           
            ans+= abs(it-med);
            
        }

        return ans;
        
    }
};