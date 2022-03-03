class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        return 0;
        int s1=0,ans=0;
        for(int i=2;i<n;i++)
        {
           if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) 
            {
              s1++;
              ans+=s1;
            }
            else
            { 
                s1=0;
            }
            
            
        }
        return ans;
    }
};