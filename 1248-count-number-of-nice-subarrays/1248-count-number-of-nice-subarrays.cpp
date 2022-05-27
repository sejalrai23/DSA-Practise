class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cum=0; 
        map<int,int> rec; 
        int cnt = 0; 
        rec[0]++; 
        for(int i=0;i<nums.size();i++){
            cum += nums[i]%2;
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};