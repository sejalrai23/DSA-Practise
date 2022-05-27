class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;
        int cnt=0,mx=0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
            }
            if(cnt<=k){
                mx=max(mx, j-i+1);
                j++;
            }else{
                while(cnt>k){
                    if(nums[i]==0){
                        cnt--;
                    }
                    i++;
                }
                // i++;
                j++;
                
            }
            
        }
        return mx;
        
    }
};