class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0,mx=0, cnt=0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
            }
            if(cnt<1){
                j++;
            }
            else if(cnt==1){
                mx=max(mx,j-i+1);
                j++;
            }else if(cnt>1){
                while(cnt>1){
                    if(nums[i]==0){
                        cnt--;
                    }
                    i++;
                }
                j++;
            }
            
        }
        return cnt==0 ? nums.size()-1 : mx-1;
        
        
    }
};