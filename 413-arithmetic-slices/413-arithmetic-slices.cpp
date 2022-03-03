class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        map<int,int> m;
        int diff=0;
        int ans=0;
         int cnt=0;
        for(int i=1;i<nums.size();i++){
            int curr=nums[i]-nums[i-1];
            if(curr==diff){
              ans+=cnt;
               cnt++;
                
            }else{
               
                
                cnt=1;
                diff=curr;
            }    
        }
        return ans;
        
    }
};