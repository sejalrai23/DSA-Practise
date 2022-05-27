class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        int cum=0; 
        map<int,int> rec; 
        int cnt = 0; 
        rec[0]++; 
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};