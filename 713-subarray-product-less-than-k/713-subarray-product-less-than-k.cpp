class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int i=0, j=0, pro=1, cnt=0,ans=0;
        while(j<nums.size()){
            pro*=nums[j];
            if(pro<k){
                cnt+=j-i+1;
                j++;
            }else{
                while(pro>=k){
                    pro/=nums[i];
                    i++;
                }
                if(pro<k){
                cnt+=j-i+1;
                }
               
                j++;
                
            }
        }
        // cout<<cnt<<endl;
        return cnt<0 ? 0 : cnt;
        
    }
};